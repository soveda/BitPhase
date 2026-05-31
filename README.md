# BitPhase

BitPhase is a hybrid **analog-style phaser, tremolo, and bit-crush processor** designed for modular-style signal processing.

It combines a classic 4-stage MXR-inspired phaser core with dual-rate LFO modulation, switchable performance modes, and a controlled digital degradation engine for unstable textures.

---

## Overview

BitPhase is built around:

- 4-stage all-pass phaser network (MXR-style topology)
- Feedback-enhanced phase shifting system
- Dual LFO architecture:
  - Phaser LFO (primary modulation)
  - Tremolo LFO (1/4-speed modulation)
- 3-mode performance switch
- Bit-crush / sample-hold degradation system

The result is a processor that moves between:
- Clean phasing movement
- Rhythmic amplitude modulation
- Chaotic degraded textures

---

## Modes

### ▲ Up — Phaser Only Mode
- Classic phaser output only
- Full 4-stage all-pass filtering
- Feedback-enhanced movement
- Cleanest tonal response

---

### ● Middle — Mix Mode
- Blends:
  - Phaser signal
  - Tremolo amplitude modulation
- Internal 50/50-style mix
- Adds rhythmic motion and stereo depth

---

### ▼ Down — Burst Mode
- Extreme instability mode
- Increased modulation intensity
- Enhanced bit degradation behaviour
- Designed for transitions, glitches, and texture collapse

---

## Controls

### Main Knob (Rate)
- Controls base modulation speed
- Drives both LFO systems:
  - Phaser LFO (full speed)
  - Tremolo LFO (1/4 speed)

---

### Knob X (Depth)
- Controls phaser sweep depth
- Determines intensity of phase shifting
- Affects overall movement range

---

### Knob Y (Character / Corruption)
- Controls bit-crush and sample-hold degradation
- Adds instability in Burst mode
- Shapes overall “lo-fi character” of output

---

## Modulation System

### Phaser LFO
- Triangle-style waveform approximation
- Full-speed modulation engine
- Controls:
  - phaser sweep frequency
  - stereo movement offset

---

### Tremolo LFO
- Same waveform family
- Runs at **1/4 speed**
- Used for amplitude modulation in Mix mode

---

## Phaser Engine

- 4 cascaded all-pass filters
- Classic MXR-style phase cancellation structure
- Feedback taken from final stage
- Tuned for stability while preserving resonance and movement

---

## Bit Degradation Engine

A controlled digital degradation system featuring:

- Sample-and-hold reduction
- Bit masking (bit depth reduction)
- Random sample repetition (corruption effect)

This stage is designed to be **musical rather than destructive**.

---

## Stereo Output

- Mono input processing
- Stereo enhancement via LFO offset
- Right channel receives phase-modulated delay movement

---

## CV Outputs

- **CV Out 1:** Phaser LFO
- **CV Out 2:** Tremolo LFO

These outputs can be used to modulate external modular systems.

---

## Design Philosophy

BitPhase is built around:

- Analog-inspired phase behaviour
- Dual time-scale modulation (fast + slow LFOs)
- Performance-first switching (no menu systems)
- Controlled instability instead of randomness
- Musical degradation instead of noise

---

## Summary

BitPhase transitions between:

- Classic phaser movement
- Slow amplitude modulation
- Degraded lo-fi instability

All controlled through a simple interface of **3 knobs + 3-mode switch**.

---

## License

MIT 
