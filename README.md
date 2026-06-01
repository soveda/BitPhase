# BitPhase

BitPhase is a hybrid phaser, tremolo, and digital degradation processor for the Music Thing Modular Workshop Computer.

Built around a 4-stage all-pass phaser inspired by classic MXR designs, BitPhase combines animated phase movement, modulation-linked tremolo, and controllable lo-fi corruption. It moves from smooth swirling textures to unstable, degraded sounds using a simple three-knob interface and performance-oriented mode switch.

---

# Features

* 4-stage all-pass phaser
* Feedback-enhanced resonance
* Dual independent LFOs
* Tremolo modulation
* Bit reduction and sample-rate reduction
* Random glitch/repeat corruption
* Performance-oriented 3-mode operation
* CV outputs for both modulation sources
* Pulse output for modulation clocking

---

# Modes

## Up — Phaser

Classic phaser mode.

* 4-stage phaser only
* Deep feedback-enhanced sweep
* Cleanest signal path
* Ideal for subtle movement or aggressive resonant phasing

---

## Middle — Phaser + Tremolo

Combines the phaser and tremolo engines.

* Fixed 50/50 blend
* Phaser movement remains dominant
* Tremolo adds rhythmic amplitude modulation
* Creates animated, pulsing textures

---

## Down — Burst

A deliberately unstable performance mode.

* Phaser speed jumps to approximately 12 Hz
* Output gain increases
* Corruption intensity increases automatically
* Designed for transitions, breakdowns, glitches, and texture destruction

Burst mode is intentionally aggressive and may introduce extreme modulation artifacts.

---

# Controls

## Main — Rate

Controls both modulation engines.

### Phaser LFO

Approximate range:

* 0.05 Hz
* 6 Hz

The response is curved for finer control at slower speeds.

### Tremolo LFO

Approximate range:

* 0.5 Hz
* 20 Hz

This provides both slow pulsing and audio-rate-style modulation effects.

---

## X — Depth

Controls the intensity of both modulation engines simultaneously.

Affects:

* Phaser sweep depth
* Tremolo depth

As X increases:

* Phaser notches move further
* Resonance becomes more dramatic
* Tremolo modulation becomes stronger

The linked behaviour is intentional and forms part of BitPhase's character.

---

## Y — Corruption

Controls the digital degradation engine.

Affects:

* Sample-rate reduction
* Bit-depth reduction
* Random sample repetition

Lower settings provide subtle instability.

Higher settings introduce:

* Crunch
* Stuttering
* Digital breakup
* Repeated sample artifacts

In Burst mode, additional corruption is automatically applied.

---

# Phaser Engine

BitPhase uses four cascaded first-order all-pass stages.

Features:

* All-pass filter topology
* Feedback taken from the final stage
* Variable sweep coefficient
* Deep notch movement
* Strong resonant character

The design is inspired by classic MXR-style phasers while intentionally pushing toward more unstable territory.

---

# Tremolo Engine

A dedicated tremolo path runs alongside the phaser.

Features:

* Triangle-wave modulation
* Independent modulation rate
* Shared depth control with the phaser
* Available in Mix mode

The tremolo is intentionally linked to phaser behaviour rather than operating as a separate effect.

---

# Corruption Engine

BitPhase includes a built-in digital degradation stage.

Processing includes:

## Sample Hold

Reduces effective sample rate by holding output values for multiple samples.

## Bit Reduction

Masks low-order bits to create digital crunch and reduced resolution.

## Random Repeats

Occasionally repeats previous samples using a pseudo-random generator.

This creates unstable, degraded textures without completely destroying the source material.

---

# Outputs

## Audio Out 1

Main processed output.

## Audio Out 2

Duplicate of Audio Out 1.

Both outputs currently carry the same signal.

---

## CV Out 1

Phaser LFO output.

Approximate range:

* -2048 to +2047

Useful for:

* Filter modulation
* VCA modulation
* External CV animation

---

## CV Out 2

Tremolo LFO output.

Approximate range:

* -2048 to +2047

Useful for:

* Fast modulation
* Rhythmic control signals
* Synchronised movement elsewhere in a patch

---

## Pulse Out 1

Burst mode status.

* High when Burst mode is active
* Low otherwise

Can be used to switch or trigger external modules when entering Burst mode.

---

## Pulse Out 2

Square-wave output derived from the Phaser LFO.

Acts as a modulation clock and follows the current phaser rate.

Useful for:

* Clocking events
* Trigger generation
* Synchronising external modulation

---

# LED Indicators

| LED   | Function              |
| ----- | --------------------- |
| LED 0 | Rate position         |
| LED 1 | Phaser LFO activity   |
| LED 2 | Phaser sweep position |
| LED 3 | Corruption amount     |
| LED 4 | Burst mode active     |
| LED 5 | Pulse input monitor   |

---

# Design Philosophy

BitPhase is not intended to be a faithful recreation of any single vintage phaser.

Instead it combines:

* Analog-inspired phase movement
* Modulation-linked behaviour
* Controlled digital degradation
* Performance-oriented switching
* Intentional instability

The goal is to blur the line between traditional modulation effects and damaged digital processing.

---

# License

MIT License
