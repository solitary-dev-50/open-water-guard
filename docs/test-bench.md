# Test Bench

## Purpose

The first testing stage should happen on a desktop water loop, not on real household plumbing.

This keeps the project manageable, visible, and safer for early board-level testing.

## Recommended Bench Items

- water tank
- small water pump
- clear flexible tubing
- flow sensor
- leak probes
- catch tray
- buzzer
- indicator LEDs
- buttons
- optional small display

## Suggested Bench Layout

A simple bench loop can be arranged like this:

1. Water tank holds the test water.
2. Small pump pushes water through clear tubing.
3. Flow sensor sits in the tubing path.
4. Catch tray sits below likely drip points.
5. Leak probes are placed in the catch tray or near intentional drip zones.
6. The controller board reads the sensors and drives buzzer, indicators, buttons, and optional display.

The clear tubing helps the user see water movement directly during tests.

## Test Cases

### Probe Touches Water

- wet one leak probe
- confirm local alert
- confirm indicator change
- confirm optional display update

### Continuous Flow

- run the pump continuously
- confirm the flow sensor is detected
- confirm the board shows active flow

### Long-Duration Low Flow

- reduce pump output to a small steady trickle
- keep the condition running
- confirm low-flow duration tracking
- confirm staged warning behavior

### Sensor Disconnect

- disconnect a probe or flow sensor
- confirm the board shows a local fault or missing-input condition

### Button Mute

- trigger a local alarm
- press mute or acknowledge
- confirm buzzer state changes correctly

### Power Loss and Recovery

- remove power
- restore power
- confirm the board boots cleanly
- confirm it returns to local sensing and local status output

## Important Scope Note

The first phase should stay on a desktop water bench.

There is no need to connect the board to a real household water line during the first testing stage.

That is the right place to verify:

- sensor reading
- low-flow detection
- buzzer behavior
- indicator behavior
- button handling
- optional display output

before deciding anything about a larger physical setup.
