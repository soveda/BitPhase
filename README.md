# BitPhase

BitPhase is a hybrid modulation and digital degradation effect for the Music Thing Modular Workshop Computer.

At its core is a traditional 4-stage phaser driven by a triangle-wave LFO, paired with a tremolo section and a digital "Bitrot" engine that introduces sample-rate reduction, bit-depth degradation, packet-repeat glitches, and triggerable corruption bursts.

Designed to move between smooth vintage-style modulation and unstable digital artifacts, BitPhase can function as a classic modulation effect, a glitch processor, or a source of animated control voltages for the rest of a patch.

---

# Features

* Traditional 4-stage phaser
* Triangle-wave LFO modulation
* Tremolo mode
* Phaser/tremolo hybrid mode
* Bitrot digital degradation engine
* Triggerable corruption bursts via pulse input
* Sample-rate reduction
* Bit-depth reduction
* Packet-repeat glitch artifacts
* Modulation hold mode
* Stereo output
* LFO CV output
* Corruption CV output
* Burst gate pulse output
* LFO pulse output

---

# Controls

## Main Knob

Controls modulation rate.

* Counter-clockwise: slow sweeps
* Clockwise: fast modulation

Affects both phaser and tremolo operation.

---

## X Knob

Controls modulation depth.

* Phaser sweep amount
* Tremolo depth

Higher settings produce deeper movement and more pronounced modulation.

---

## Y Knob

Controls Bitrot intensity.

At low settings the signal remains relatively clean.

As the control is increased, BitPhase introduces:

* Sample-rate reduction
* Bit-depth reduction
* Sample repetition artifacts
* More aggressive corruption bursts

---

# Switch Modes

## Up — Tremolo

Pure tremolo mode.

The signal is amplitude-modulated by the internal LFO.

Useful for rhythmic pulsing and volume animation.

---

## Middle — Phaser + Tremolo Morph

The phaser and tremolo engines are blended together.

Audio/CV Input 2 controls the balance between the two effects.

This mode provides the most movement and is intended as the primary performance mode.

---

## Down — Hold

Freezes the modulation LFO at its current position.

The phaser and tremolo remain locked in place while the Bitrot engine continues to operate.

Useful for capturing sweet spots or creating static filtered textures.

---

# Inputs

## Audio Input 1

Main audio input.

All processing is applied to this signal.

---

## Audio/CV Input 2

Morph control input.

In Middle mode this input controls the blend between:

* Phaser
* Tremolo

Audio-rate signals can produce complex modulation interactions.

CV sources can automate the effect balance.

---

## Pulse Input 1

Corruption Burst Trigger.

Each rising edge triggers a temporary increase in Bitrot intensity.

Useful for rhythmic glitches, fills, and transitions.

---

## Pulse Input 2

Currently unused.

Available for future expansion or custom modifications.

---

# Outputs

## Audio Output 1

Main processed signal.

---

## Audio Output 2

Processed signal with additional stereo modulation offset.

Provides width and movement when monitoring in stereo.

---

## CV Output 1

LFO output.

Tracks the internal modulation waveform.

Useful for synchronising external modulation.

---

## CV Output 2

Bitrot output.

Represents current corruption intensity.

Can be used to drive external modulation destinations.

---

## Pulse Output 1

Corruption Burst Gate.

Goes high while a corruption burst is active.

Useful for triggering other modules in response to glitches.

---

## Pulse Output 2

LFO Pulse Output.

Produces a pulse derived from the internal modulation cycle.

Useful as a clock or modulation timing source.

---

# LED Functions

| LED | Function                |
| --- | ----------------------- |
| 0   | Modulation rate         |
| 1   | LFO position            |
| 2   | Phaser sweep amount     |
| 3   | Bitrot intensity        |
| 4   | Corruption burst active |
| 5   | Pulse Input 1 activity  |

---

# Patch Ideas

## Corrupted Tremolo

* Switch Up
* Medium modulation rate
* High Bitrot

Produces degraded rhythmic pulsing reminiscent of damaged digital playback.

---

## Glitch Phaser

* Switch Middle
* Moderate depth
* Pulse Input 1 clocked from a sequencer

Injects bursts of corruption into sweeping phaser textures.

---

## CV Generator

Use:

* CV Output 1 as an LFO source
* CV Output 2 as a corruption envelope
* Pulse Output 2 as a modulation clock

BitPhase can function as both an audio effect and a modulation source.

---

# Technical Notes

BitPhase currently implements:

* Four cascaded all-pass stages
* Triangle-wave modulation
* Tremolo amplitude modulation
* Sample-and-hold degradation
* Bit-depth reduction
* Random sample repetition
* Triggerable corruption bursts

The design intentionally combines traditional modulation effects with digital failure modes, creating sounds that range from smooth movement to unstable, broken-data textures.
