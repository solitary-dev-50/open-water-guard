# BOM

## First-Version Scope

This BOM is for the **detection and local alerting layer only**.
It supports a fully offline DIY controller board with no internet connection, no cloud path, and no household data upload.

It does not require:

- valves
- electric ball valves
- clamp-on actuators
- plumbing installation hardware

If actuator hardware is mentioned at all, it belongs only to a **future optional experiment** layer.

## Core Controller Items

- ESP32 or ESP32-S3 controller board
- leak probes
- flow sensor
- buzzer
- indicator LEDs
- buttons
- optional display
- power module
- jumper wires and terminal blocks

## Desktop Test Items

- small water pump
- water tank
- clear flexible tubing
- catch tray

## Recommended First-Pass Buying Logic

The first bench build should prioritize:

- easy wiring
- visible water movement
- simple local alerts
- repeatable low-flow tests
- low replacement cost

The goal is to prove the board-level sensing loop first:

- probe input
- flow input
- low-flow timing
- buzzer output
- indicator output
- button handling
- optional display output

## Future Optional Experiment

Not part of the required first-version BOM, but may appear later as optional experiments:

- valve actuators
- electric ball valves
- actuator brackets
- actuator driver hardware
