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
- includes first-pass GPIO wiring for leak probes, flow pulse input, buzzer, status LED, mute button, and acknowledge button
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
  - local buzzer output on `GPIO15`

- `alarm/StatusLed`
  - local indicator output on `GPIO16`

- `sensors/LeakSensor`
  - single active-low probe input

- `sensors/LeakSensorManager`
  - three active-low probe inputs

- `sensors/FlowSensor`
  - interrupt-based pulse counter on `GPIO7`

- `rules/RuleEngine`
  - simple offline local alert decisions

- `config/ConfigManager`
  - early configuration placeholder

- `logs/EventLog`
  - in-memory log placeholder

- `power/PowerManager`
  - power summary placeholder

- `controls/LocalButtons`
  - active-low mute and acknowledge button inputs

- `time/TimeUtils`
  - local time helper utilities

## Not Implemented Yet

- calibrated low-flow timing
- persistent event storage
- optional display module
- button debounce
- real sensor fault detection
- full power-loss recovery behavior
- complete test-bench validation

## Pin Placeholder Table

These are first-pass ESP32-S3 DevKitC-1 assignments for desktop bench wiring. They may still change before PCB work.

| Function | GPIO | Notes |
| --- | --- | --- |
| Leak probe 1 | `GPIO4` | washer, active-low with internal pull-up |
| Leak probe 2 | `GPIO5` | heater, active-low with internal pull-up |
| Leak probe 3 | `GPIO6` | kitchen, active-low with internal pull-up |
| Flow pulse input | `GPIO7` | rising-edge interrupt, internal pull-up |
| Buzzer output | `GPIO15` | active-high output |
| Status LED output | `GPIO16` | active-high output |
| Mute button | `GPIO17` | active-low with internal pull-up |
| Acknowledge button | `GPIO18` | active-low with internal pull-up |
| Optional display bus | `TBD` | not implemented yet |

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
