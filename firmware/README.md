# Open Water Guard Firmware

This directory contains an **early prototype / work in progress** firmware base for the Open Water Guard offline sensing layer.

## Position

This is a **fully offline firmware prototype**.

It is for:

- sensing
- local alerting
- serial debugging
- desktop test-bench bring-up

It is **not** for:

- internet connection
- cloud services
- household data upload
- mobile app integration
- automatic shutoff
- valve-actuator control
- commercial control layers

## Current Status

Current state:

- compiles as a PlatformIO Arduino prototype for `esp32-s3-devkitc-1`
- provides a modular app structure
- includes stub modules for leak sensing, flow sensing, buzzer, status LED, event log, config, and power summary
- prints boot and periodic local status over serial

This firmware is not a finished product. It is a maintainable early base for offline detection-layer development.

## Current Implemented Modules

- `main.cpp`
  - board entrypoint
  - serial startup
  - application object wiring

- `app/AppController`
  - setup and loop orchestration
  - module polling
  - rule evaluation
  - local output updates
  - serial heartbeat output

- `alarm/Buzzer`
  - local buzzer state placeholder

- `alarm/StatusLed`
  - local indicator state placeholder

- `sensors/LeakSensor`
  - single probe state placeholder

- `sensors/LeakSensorManager`
  - multi-probe container and summary

- `sensors/FlowSensor`
  - flow summary placeholder

- `rules/RuleEngine`
  - simple offline local alert decisions

- `config/ConfigManager`
  - early configuration placeholder

- `logs/EventLog`
  - in-memory log placeholder

- `power/PowerManager`
  - power summary placeholder

- `time/TimeUtils`
  - local time helper utilities

## Not Implemented Yet

- real GPIO pin reads
- interrupt-based pulse counting
- calibrated low-flow timing
- persistent event storage
- optional display module
- button debounce and button action handling
- real sensor fault detection
- full power-loss recovery behavior
- complete test-bench validation

## Pin Placeholder Table

These are placeholders only. They are not final hardware assignments.

| Function | Placeholder | Notes |
| --- | --- | --- |
| Leak probe 1 | `TBD` | final pin not assigned |
| Leak probe 2 | `TBD` | final pin not assigned |
| Leak probe 3 | `TBD` | final pin not assigned |
| Flow pulse input | `TBD` | final pin not assigned |
| Buzzer output | `TBD` | final pin not assigned |
| Status LED output | `TBD` | final pin not assigned |
| Mute button | `TBD` | final pin not assigned |
| Acknowledge button | `TBD` | final pin not assigned |
| Optional display bus | `TBD` | final pin not assigned |

## Test-Bench Plan

This firmware is intended to be exercised first on a desktop water loop:

- water tank
- small pump
- clear tubing
- flow sensor
- leak probes
- catch tray
- buzzer
- status LED
- local buttons
- optional display later

The first useful milestones are:

1. boot and serial heartbeat
2. probe wet/dry state reporting
3. flow present / no-flow reporting
4. low-flow timing placeholder
5. buzzer and LED alert response
6. mute / acknowledge button handling

## Build

Expected build command:

```text
pio run
```

Current board target:

```text
esp32-s3-devkitc-1
```
