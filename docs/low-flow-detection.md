# Low-Flow Detection

## Why Low Flow Matters

A small but continuous water flow lasting for 1-2 hours can indicate a real household problem even if no leak probe is wet.

Possible examples include:

- a slowly leaking toilet
- a faucet not fully closed
- a purifier problem
- an ice maker problem
- irrigation left active
- a hidden slow leak

## What Low Flow Does Not Mean

Low flow should **not** be treated as identical to a confirmed leak.

It may be:

- normal appliance behavior
- irrigation timing
- a user forgetting to close something fully
- a small but harmless short-duration event

That is why the first version should only **warn locally**. It should not shut off water automatically.

## First-Version Position

The first release uses low-flow detection as a local reminder and suspicion signal.
It is part of a fully offline DIY controller board and a sensing-and-alerting-only first release.

It does not:

- upload household water data
- use any internet connection
- trigger automatic shutoff

All logic is intended to run fully on the controller board.

## Suggested Risk Levels

### Observe

Small flow is present, but the duration is still short.

Example:

- short-duration trickle
- user may still be using water

### Reminder

Small flow has lasted longer than expected and deserves attention.

Example:

- possible dripping faucet
- possible toilet refill issue

### Highly Suspicious

Small flow continues long enough that the board should make the user check it soon.

Example:

- long toilet slow leak
- hidden equipment issue

### High Risk

Small flow continues unusually long or appears together with other local warning signals.

Example:

- repeated long-duration low-flow events
- suspicious low-flow with another local anomaly

Even at this stage, the first version should still focus on **local alerting only**.

## Local-Only Evaluation

All low-flow evaluation should stay on the board:

- pulse counting
- duration tracking
- local risk grading
- buzzer activation
- indicator changes
- optional display output

No household water-use history needs to be uploaded anywhere.
No internet connection and no cloud path are required for this logic.

## Practical Goal

The practical goal is to help users notice strange long-duration water behavior early, without pretending every small flow is a leak and without pushing the project into online surveillance or automatic shutoff claims.
