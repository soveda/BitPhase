//
// BitPhase.cpp
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
        int32_t yKnob     = KnobVal(Knob::Y);
        int32_t k = rateKnob; // 0–4095
        float norm = (float)k / 4095.0f;
        

        //----------------------------------------
        // Mode select

        enum Mode { PHASER_ONLY, MIX, BURST };

        Mode mode;
        switch (SwitchVal())
        {
            case Switch::Up:    mode = PHASER_ONLY; break;
            case Switch::Middle:mode = MIX; break;
            default:            mode = BURST; break;
        }

        //----------------------------------------
        // LFO clocks
        
        float slowAmt = norm * norm;   // from earlier knob normalization

        float phaserHz = 0.05f + slowAmt * (6.0f - 0.05f);

        uint32_t phaserInc =
            (uint32_t)((phaserHz * PHASE_SCALE) / FS);

        
        float fastAmt = norm;

        float tremHz = 0.5f + fastAmt * (20.0f - 0.5f);

        uint32_t tremInc =
            (uint32_t)((tremHz * PHASE_SCALE) / FS);

        
        if (mode != BURST)
        {
            phaserPhase += phaserInc;
            tremPhase   += tremInc;
            }
        else
        {
            float burstHz = 12.0f;

            phaserPhase +=
                (uint32_t)((burstHz * PHASE_SCALE) / FS);
            tremPhase   += 50000;
        }
        
        //----------------------------------------
        // Triangle LFO generator

        auto triLFO = [](uint32_t p) -> int32_t
        {
            uint32_t v = (p >> 20) & 4095;
            int32_t x = (v < 2048) ? v : (4095 - v);
            return (x - 1024) << 1;
        };

        int32_t phaserLfo = triLFO(phaserPhase);
        int32_t tremLfo   = triLFO(tremPhase);

        //----------------------------------------
        // Depth control (X = phaser intensity)

        int32_t sweep =
            768 + ((phaserLfo * depthKnob) >> 12);;

        if (sweep < 96)   sweep = 96;
        if (sweep > 1920) sweep = 1920;

        //----------------------------------------
        // Tremolo

        int32_t tremGain =
            2048 + ((tremLfo * depthKnob) >> 12);

        if (tremGain < 0) tremGain = 0;

        int32_t tremolo =
            (in * tremGain) >> 11;

        //----------------------------------------
        // MXR-style 4-stage phaser with feedback

        int32_t input = in + ((fb * 3000) >> 12);

        int32_t x = input;
        int32_t y;

        y = ap1_z1 + (((sweep * (x - ap1_y1)) >> 11));
        ap1_z1 = x; ap1_y1 = y; x = y;

        y = ap2_z1 + (((sweep * (x - ap2_y1)) >> 11));
        ap2_z1 = x; ap2_y1 = y; x = y;

        y = ap3_z1 + (((sweep * (x - ap3_y1)) >> 11));
        ap3_z1 = x; ap3_y1 = y; x = y;

        y = ap4_z1 + (((sweep * (x - ap4_y1)) >> 11));
        ap4_z1 = x; ap4_y1 = y;

        int32_t phaser = ((in * 3) >> 2) - y;

        fb = y >> 1;         // 0.5

        //----------------------------------------
        // Mode routing

        int32_t output = phaser;

        if (mode == MIX)
        {
            int32_t mix = 2048; // 50/50 fixed mix

            output =
                ((phaser * mix) +
                 (tremolo * (4095 - mix))) >> 12;
        }
        else if (mode == BURST)
        {
            output = phaser + (phaser >> 1);
        }

        //----------------------------------------
        // Bitcrush / lo-fi (Y now also influences texture slightly)

        int32_t corruption = yKnob;

        if (mode == BURST)
            corruption += 1500;

        if (corruption > 4095)
            corruption = 4095;

        uint32_t holdLength = 1 + (corruption >> 8);

        if (++holdCounter >= holdLength)
        {
            heldSample = output;
            holdCounter = 0;
        }

        output = heldSample;

        uint32_t maskShift = corruption >> 10;
        output = (output >> maskShift) << maskShift;

        rng = rng * 1664525u + 1013904223u;

        uint32_t repeatChance = corruption >> 3;
        if ((rng & 0x3FF) < repeatChance)
            output = previousOutput;

        previousOutput = output;

        //----------------------------------------
        // Output

        AudioOut1(output);
        AudioOut2(output + ((phaserLfo * 256) >> 12));

        //----------------------------------------
        // CV

        CVOut1(phaserLfo);
        CVOut2(tremLfo);

        //----------------------------------------
        // Pulses

        PulseOut1(mode == BURST);

        bool lfoPulse = (phaserPhase & 0x80000000);
        PulseOut2(lfoPulse);

        //----------------------------------------
        // LEDs (fixed scaling)

        LedBrightness(0, rateKnob);

        int32_t lfoLed = (phaserLfo + 2048);
        if (lfoLed < 0) lfoLed = 0;
        if (lfoLed > 4095) lfoLed = 4095;
        LedBrightness(1, lfoLed);

        int32_t sweepLed = sweep;
        LedBrightness(2, (sweep * 4095) / 1920);

        int32_t corrLed = corruption;
        if (corrLed > 4095) corrLed = 4095;
        LedBrightness(3, corrLed);

        LedOn(4, mode == BURST);
        LedOn(5, PulseIn1());
    }

private:
    
    static constexpr float FS = 48000.0f;
    static constexpr float PHASE_SCALE = 4294967296.0f;
    
    uint32_t phaserPhase = 0;
    uint32_t tremPhase   = 0;

    int32_t ap1_z1 = 0, ap1_y1 = 0;
    int32_t ap2_z1 = 0, ap2_y1 = 0;
    int32_t ap3_z1 = 0, ap3_y1 = 0;
    int32_t ap4_z1 = 0, ap4_y1 = 0;

    int32_t fb = 0;

    uint32_t rng = 1;

    uint32_t holdCounter = 0;
    int32_t heldSample = 0;

    int32_t previousOutput = 0;
};

int main()
{
    BitPhase card;
    card.Run();
}
