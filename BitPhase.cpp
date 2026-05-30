//
//  BitPhase.cpp
//
//
//  Created by Adrian Vos on 30/05/2026.
//


#include "ComputerCard.h"

class BitPhase : public ComputerCard
{
public:

    virtual void ProcessSample() override
    {
        int32_t in = AudioIn1();

        int32_t rateKnob  = KnobVal(Knob::Main);
        int32_t depthKnob = KnobVal(Knob::X);
        int32_t bitrotKnob = KnobVal(Knob::Y);

        //----------------------------------------
        // Burst trigger

        if (PulseIn1RisingEdge())
        {
            burstCounter = 12000 + ((bitrotKnob * 24000) >> 12);
        }

        if (burstCounter > 0)
            burstCounter--;

        bool burstActive = burstCounter > 0;

        //----------------------------------------
        // LFO

        if (SwitchVal() != Switch::Down)
        {
            uint32_t increment =
                20 + ((uint32_t)rateKnob << 2);

            phase += increment;
        }

        int32_t lfo =
            (phase & 0x80000000)
            ? (0xFFFFFFFF - phase) >> 19
            : phase >> 19;

        lfo -= 2048;

        //----------------------------------------
        // Tremolo

        int32_t depth = depthKnob;

        int32_t tremGain =
            2048 + ((lfo * depth) >> 12);

        if (tremGain < 0)
            tremGain = 0;

        int32_t tremolo =
            (in * tremGain) >> 11;

        //----------------------------------------
        // Phaser coefficient

        int32_t sweep =
            1024 +
            ((lfo * depthKnob) >> 13);

        if (sweep < 64)
            sweep = 64;

        if (sweep > 1984)
            sweep = 1984;

        //----------------------------------------
        // Four-stage allpass phaser

        int32_t x;
        int32_t y;

        x = in;
        y = ap1_z1 + (((sweep * (x - ap1_y1)) >> 11));
        ap1_z1 = x;
        ap1_y1 = y;

        x = y;
        y = ap2_z1 + (((sweep * (x - ap2_y1)) >> 11));
        ap2_z1 = x;
        ap2_y1 = y;

        x = y;
        y = ap3_z1 + (((sweep * (x - ap3_y1)) >> 11));
        ap3_z1 = x;
        ap3_y1 = y;

        x = y;
        y = ap4_z1 + (((sweep * (x - ap4_y1)) >> 11));
        ap4_z1 = x;
        ap4_y1 = y;

        int32_t phaser =
            (in + y) >> 1;

        //----------------------------------------
        // Blend modulation from Audio/CV In 2

        int32_t blendCV = AudioIn2();

        int32_t blend =
            2048 + blendCV;

        if (blend < 0)
            blend = 0;

        if (blend > 4095)
            blend = 4095;

        int32_t combined =
            ((phaser * (4095 - blend))
            + (tremolo * blend))
            >> 12;

        //----------------------------------------
        // Switch modes

        int32_t output;

        switch (SwitchVal())
        {
            case Switch::Up:
                output = tremolo;
                break;

            case Switch::Middle:
                output = combined;
                break;

            default:
                output = combined;
                break;
        }

        //----------------------------------------
        // Bitrot

        int32_t corruption =
            bitrotKnob;

        if (burstActive)
            corruption += 1500;

        if (corruption > 4095)
            corruption = 4095;

        uint32_t holdLength =
            1 + (corruption >> 8);

        if (++holdCounter >= holdLength)
        {
            heldSample = output;
            holdCounter = 0;
        }

        output = heldSample;

        uint32_t maskShift =
            corruption >> 10;

        output =
            (output >> maskShift)
            << maskShift;

        rng =
            rng * 1664525u +
            1013904223u;

        uint32_t repeatChance =
            corruption >> 3;

        if ((rng & 0x3FF) < repeatChance)
        {
            output = previousOutput;
        }

        previousOutput = output;

        //----------------------------------------
        // Stereo output

        AudioOut1(output);

        AudioOut2(
            output +
            ((lfo * 256) >> 12));

        //----------------------------------------
        // CV outputs

        CVOut1(lfo);

        CVOut2(
            (corruption - 2048));

        //----------------------------------------
        // Pulse outputs

        PulseOut1(burstActive);

        bool lfoPulse =
            ((phase & 0x80000000) != lastLfoState);

        PulseOut2(lfoPulse);

        lastLfoState =
            (phase & 0x80000000);

        //----------------------------------------
        // LEDs

        LedBrightness(0, rateKnob);

        LedBrightness(1,
            (lfo + 2048));

        LedBrightness(2,
            sweep << 1);

        LedBrightness(3,
            corruption);

        LedOn(4, burstActive);

        LedOn(5,
            PulseIn1());
    }

private:

    uint32_t phase = 0;

    int32_t ap1_z1 = 0;
    int32_t ap1_y1 = 0;

    int32_t ap2_z1 = 0;
    int32_t ap2_y1 = 0;

    int32_t ap3_z1 = 0;
    int32_t ap3_y1 = 0;

    int32_t ap4_z1 = 0;
    int32_t ap4_y1 = 0;

    uint32_t rng = 1;

    uint32_t holdCounter = 0;
    int32_t heldSample = 0;

    int32_t previousOutput = 0;

    uint32_t burstCounter = 0;

    bool lastLfoState = false;
};

int main()
{
    BitPhase card;
    card.Run();
}
