# BitPhase

BitPhase is a hybrid phaser, tremolo, and digital degradation processor for the Music Thing Modular Workshop Computer.

Built around a 4-stage all-pass phaser core, BitPhase combines classic phase-shifting movement with linked tremolo modulation, clock-syncable LFO behavior, and controllable lo-fi corruption.

The design intentionally blends traditional modulation effects with unstable digital character.

---

## Features

* 4-stage all-pass phaser engine
* Feedback-enhanced resonance
* Dual LFO architecture
* External clock sync for phaser modulation
* Linked phaser/tremolo depth control
* Sample-rate reduction and bit degradation
* Random sample-repeat corruption
* Three performance modes
* CV outputs for modulation signals
* Pulse outputs for synchronization

---

## Modes

### ▲ Up — Phaser

Classic phaser operation.

* 4-stage all-pass phasing
* Feedback resonance
* Clock-syncable phaser LFO
* Cleanest operating mode

---

### ● Middle — Mix

Combines:

* Phaser
* Tremolo

at a fixed 50/50 blend.

The tremolo depth follows the same depth control as the phaser, creating tightly linked modulation behavior.

---

### ▼ Down — Burst

Deliberately unstable mode.

Changes include:

* Fixed high-speed phaser sweep
* Increased corruption intensity
* Enhanced modulation instability
* Aggressive resonance behavior

Burst mode is designed as a performance effect rather than a traditional phaser setting.

---

## Controls

### Main Knob — Rate

Controls both modulation engines.

#### Phaser LFO

Range:

* 0.05 Hz to 6 Hz

Uses a squared response curve for finer control at slower speeds.

#### Tremolo LFO

Range:

* 0.5 Hz to 20 Hz

Runs independently from the phaser.

---

### X Knob — Depth

Controls:

* Phaser sweep depth
* Tremolo depth

Both modulation systems intentionally share the same depth control.

Increasing X creates:

* Deeper phaser notches
* Stronger tremolo movement
* More dramatic modulation overall

---

### Y Knob — Character

Controls the degradation engine.

Maximum range is approximately 75% of the system's full corruption capability.

Affects:

* Sample-and-hold reduction
* Bit-depth reduction
* Random sample repetition

At higher settings the signal becomes progressively dirtier and more unstable.

---

## Clock Synchronization

Pulse In can synchronize the phaser LFO.

Every rising edge:

* Resets the phaser LFO phase
* Leaves the tremolo LFO running freely

This allows:

* Rhythmically locked phasing
* Evolving interaction between phaser and tremolo

The result is a modulation pattern that stays synchronized while retaining movement and variation.

---

## Phaser Engine

BitPhase uses:

* Four cascaded first-order all-pass stages
* Feedback taken from the final stage
* Dry/wet phase cancellation for notch generation

The architecture is inspired by classic MXR-style phasers while using a digital implementation suitable for Workshop Computer hardware.

---

## Degradation Engine

The character section combines several digital processes:

### Sample Hold

Reduces update frequency by holding previous samples.

### Bit Reduction

Reduces effective bit depth through masking.

### Repeat Corruption

Randomly repeats previous output samples to create glitches and unstable textures.

The degradation system is intended to remain musical across most of its range while becoming increasingly aggressive at higher settings.

---

## Inputs

### Audio In

Mono audio input.

### Pulse In

External clock or trigger input.

Used to reset and synchronize the phaser LFO.

---

## Outputs

### Audio Out 1

Main processed signal.

### Audio Out 2

Duplicate of the main processed signal.

Useful for sending the same processed audio to multiple destinations.

### CV Out 1

Phaser LFO output.

Can be used to modulate external modules.

### CV Out 2

Tremolo LFO output.

Provides a second modulation source running independently of the phaser sync system.

### Pulse Out 1

Burst mode indicator.

High while Burst mode is active.

### Pulse Out 2

Phaser LFO phase pulse.

Tracks the upper half of the phaser LFO cycle.

Useful as a modulation timing signal.

---

## LEDs

### LED 1

Rate control position.

### LED 2

Phaser LFO position.

### LED 3

Current sweep amount.

### LED 4

Corruption intensity.

### LED 5

Burst mode indicator.

### LED 6

Pulse input monitor.

---

## Design Philosophy

BitPhase intentionally combines:

* Traditional phaser movement
* Linked tremolo interaction
* External synchronization
* Controlled digital degradation
* Performance-oriented instability

Rather than recreating a specific vintage pedal, BitPhase is designed as a modular modulation processor that can move from subtle phasing to broken digital textures using a minimal control set.

---

## License

MIT
