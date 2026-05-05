# Open Water Guard (OWG)

> We believe every family deserves a guard they can trust, without a subscription fee.

**My Water, My Guard.**

Open Water Guard is an offline-first ESP32/ESP32-S3 water safety project for home leak monitoring, local alarms, and cautious main-valve shutoff.

It is designed around a simple belief: the final authority over a family's main water valve should stay inside the home.

## Driven by Iris

OWG is driven by Iris, a control mindset focused on state awareness, physical execution, and result verification.

In this project, that means:

- Detect water risks locally.
- Warn the user before taking action.
- Keep automatic shutoff behind explicit local rules enabled by the user.
- Move the valve only under clear rules.
- Verify whether the water actually stopped.

## What It Tries To Solve

Common home water failures include:

- Washing machine hose bursts.
- Water heater leaks.
- Kitchen sink leaks.
- Running toilets.
- Dripping faucets.
- Basement pipe leaks.
- Hidden long-duration low-flow leaks.

Many leak alarms only beep. OWG tries to go further: detect, warn, log, and, when the user allows it, shut off the main valve locally.

## Core Ideas

### Offline First

The core safety loop should work without the internet:

- Local sensors.
- Local alarm.
- Local web console.
- Local valve control.
- Local event logs.

Cloud notification can be useful, but it should not be the final authority.

### Always Offline

OWG is designed to stay offline by default and by principle.

- No cloud command path.
- No subscription dependency.
- No remote authority over the main valve.
- Automatic shutoff can only come from local rules explicitly enabled by the user.
- The user can always cancel, enter maintenance mode, or control the valve on site.

### Closed-Loop Shutoff

Closing the valve is not the end. Confirming downstream flow has stopped is the loop.

OWG should not only ask, "Did the motor move?"

It should also ask, "Did the water actually stop?"

### Haptic Water-Pulse

Haptic Water-Pulse is a v2 research direction.

The idea is to warn people through the water itself before shutting it off: a brief, controlled pressure pulse can tell a person who is showering or using water that the system suspects a leak.

This is not a first-version promise. It needs careful safety validation.

## First-Version Direction

The first version should stay conservative:

- ESP32-S3 controller.
- 3-4 leak probe inputs.
- Water flow sensor.
- Electric ball valve.
- Buzzer and status LED.
- Physical buttons.
- Backup power path.
- Local web console.
- Event logs.

Default mode: alarm only. Automatic shutoff must be explicitly enabled by the user.

## Documentation

The structured knowledge base is in [DOC/](DOC/00-知识库索引.md).

The original Chinese brainstorming draft is archived here:

- [原始头脑风暴草稿](DOC/archive/原始头脑风暴草稿.md)
