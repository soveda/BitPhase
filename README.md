Here’s a clean README that matches your **current final code exactly**, including the corrected phaser mix, feedback, tremolo behavior, and the capped burst corruption logic.

---

# BitPhase

BitPhase is a hybrid phaser, tremolo, and digital degradation processor for the Music Thing Modular Workshop Computer.

It combines a 4-stage all-pass phaser core with linked tremolo modulation and a controlled digital corruption system that becomes increasingly unstable in Burst mode.

The design prioritises playable instability rather than strict emulation, with carefully limited chaos to avoid signal collapse at extreme settings.

---

## Features

* 4-stage all-pass phaser engine
* Feedback-enhanced phasing
* Dual LFO system (phaser + tremolo)
* Tempo-synchronisable phaser LFO reset via pulse input
* Linked tremolo depth control (shared with Y modulation)
* Three performance modes
* Controlled digital degradation system
* Bit reduction, sample-hold, and repeat corruption
* CV inputs for modulation extension
* CV outputs for both LFOs
* Pulse outputs for sync and timing

---

## Signal Overview

BitPhase processes audio in this order:

1. Input
2. Phasing (4-stage all-pass network + feedback)
3. Tremolo modulation (derived from phaser signal in MIX mode)
4. Mode-dependent degradation (Burst only)
5. Output filtering (minimal / optional)
6. Output

---

## Modes

### ▲ Up — Phaser

Classic phaser mode.

* 4-stage all-pass phasing network
* Feedback for resonance and movement
* Slow/fast LFO-controlled sweep
* Cleanest signal path

Best for:

* Sweeping phase textures
* Subtle movement
* Clean modulation effects

---

### ● Middle — Mix

Balanced combination of phaser and tremolo.

* Phaser signal + tremolo-modulated phaser blend
* Tremolo depth follows Y modulation system
* 50/50 blend of both processes

This mode introduces amplitude movement without destroying phase clarity.

---

### ▼ Down — Burst

High-intensity degradation mode.

Adds:

* Increased corruption amount (Y + fixed burst boost)
* Sample-and-hold stepping
* Bit-depth reduction (masking)
* Random sample repetition
* Increased instability in timing and texture

Important design note:
Burst corruption is **intentionally capped (~3800 max)** to prevent total signal collapse or silence at extreme Y values.

---

## Controls

### Main Knob — Rate

Controls both LFO systems.

#### Phaser LFO

* 0.05 Hz → 6 Hz
* Slow exponential feel at low settings

#### Tremolo LFO

* 0.5 Hz → 20 Hz
* Runs continuously and independently (except reset sync on phaser pulse)

---

### X Knob — Depth

Controls **phaser sweep depth only**

* Increases phaser notch movement
* Does NOT directly scale tremolo depth anymore
* Primary control for phaser intensity

Higher values produce:

* Wider sweep range
* Stronger resonance movement

---

### Y Knob — Corruption / Character

Controls digital degradation amount.

Affects:

* Sample-and-hold rate
* Bit reduction strength
* Random repeat probability
* Burst instability scaling

Important:

* Y is capped internally to prevent system collapse
* In Burst mode, additional fixed corruption is added
* Extreme values are intentionally limited to avoid silence or DC collapse

---

## Clock / Sync

Pulse Input resets the phaser LFO phase.

* Rising edge resets phaser LFO
* Tremolo LFO continues freely

This creates:

* Rhythmic phasing resets
* Evolving phaser/tremolo interaction
* Locked phase starts with drifting amplitude modulation

---

## Phaser Engine

The phaser uses:

* 4 cascaded all-pass filters
* Feedback taken from the wet output (reduced to prevent instability)
* Phase cancellation mix:

[
\text{phaser} = (input \cdot 4096 - wet \cdot 3072) >> 12
]

This produces notch-based filtering similar to classic analog phasers, but with extended digital stability.

---

## Tremolo System

Tremolo is derived from:

* A separate LFO
* Modulation applied to the phaser output (not raw input)

In MIX mode:

* Tremolo is blended with phaser output
* Maintains clarity instead of full amplitude chopping

---

## Degradation System (Burst Mode)

Burst mode introduces controlled digital damage:

### Sample & Hold

* Reduces update rate by holding previous samples

### Bit Reduction

* Applies bit masking for lo-fi texture

### Repeat Corruption

* Randomly replays previous samples

### Chaos Limiting

* Corruption is capped (~3800 max)
* Prevents silence, DC lock, or total collapse

---

## Outputs

### Audio Out 1 / 2

Stereo duplicate of processed signal

---

### CV Out 1

Phaser LFO waveform

---

### CV Out 2

Tremolo LFO waveform

---

### Pulse Out 1

High when Burst mode is active

---

### Pulse Out 2

Phaser LFO phase marker (upper half-cycle indicator)

---

## LEDs

* LED 1: Rate knob position
* LED 2: Phaser LFO position
* LED 3: Sweep amount
* LED 4: Corruption intensity
* LED 5: Burst mode indicator
* LED 6: Pulse input monitor

---

## Design Philosophy

BitPhase is designed around controlled instability:

* Clean phasing at low settings
* Musical modulation in MIX mode
* Controlled degradation in Burst mode
* No full signal destruction at extremes

The system intentionally avoids:

* Silence at high Y values
* DC runaway feedback
* Over-aggressive attenuation

Instead, it focuses on:

> playable chaos with defined limits

---

## License

MIT
