# Detection Architecture

## System Goal

The first open release of Open Water Guard is an offline DIY controller board for household water monitoring experiments.

Its goal is to:

- read leak probes
- read a flow sensor
- evaluate simple local conditions
- alert locally with a buzzer and indicators
- support mute and acknowledgement buttons
- optionally show local status on a small display

It is meant to help makers build a local detection board, not a finished anti-leak appliance.
The first release is for sensing and local alerting only.

## Detection Layer Boundary

This first-layer architecture includes:

- leak detection inputs
- flow sensing input
- low-flow duration tracking
- local buzzer alerts
- local indicator outputs
- local button handling
- optional local display output

This first-layer architecture does **not** include:

- automatic shutoff
- network functions
- no cloud functions
- mobile app integration
- remote control

## Leak Probe Inputs

Leak probes are the first direct signal for water where it should not be.

Typical first-version probe locations:

- near a washing machine
- under a water heater
- under a kitchen sink
- near a basement utility area

The controller board should treat leak probes as simple local inputs that can trigger local alerts and logging.

## Flow Sensor Input

The flow sensor provides a second type of signal: water is moving somewhere in the monitored line.

This helps the board distinguish between:

- no water activity
- active flow
- long-duration flow
- suspicious low-flow that lasts too long

The first version only needs practical local readings. It does not need utility-grade metering.

## Continuous Low-Flow Detection

A small water flow that continues for a long time can be suspicious even when no floor probe is wet.

Examples include:

- a running toilet
- a faucet not fully closed
- a purifier problem
- an ice maker problem
- irrigation left active
- a hidden slow leak

The first release should treat this as a **local warning problem**, not an automatic shutoff decision.

## Buzzer Alert

The buzzer is the simplest local signal when the board sees something worth attention.

The first version should support:

- normal silent state
- alert state
- muted state after button acknowledgement

The buzzer is part of the local detection layer, not proof of a leak by itself.

## Indicator States

Indicators help users read the board quickly without opening a web page or display.

Suggested first-version states:

- normal
- observing
- warning
- alarm
- muted
- sensor fault
- power fault

## Button Handling

The first release should support local buttons for:

- mute
- acknowledge
- optional test/reset

Buttons are important because the project is fully offline. The user must be able to interact with the board with no internet connection, no cloud path, and no phone app.

## Optional Display Output

A small display is optional, not required.

If present, it may show:

- sensor status
- current flow state
- low-flow duration
- mute state
- recent local alarm reason

The display should remain local-only.

## Fully Offline Runtime Flow

The intended runtime flow is:

1. Read leak probe inputs.
2. Read flow pulses.
3. Track no-flow, flow, and long-duration low-flow conditions.
4. Evaluate simple local detection rules on the board.
5. Drive buzzer, indicators, and optional display locally.
6. Wait for local button acknowledgement or mute input.

No internet connection, no cloud path, and no data upload are required anywhere in this flow.

## Exclusions

To keep the first release clear, the following are outside the detection-layer scope:

- automatic shutoff
- actuator control
- plumbing installation guidance
- phone app workflows
- online dashboards
- remote household data collection
