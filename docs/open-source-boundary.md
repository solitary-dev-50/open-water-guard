# Open Water Guard - Open Source Boundary and Commercial Use Policy

## Short Summary

Open Water Guard uses a layered sharing model.

- Open-source: offline sensing and local alerting layer.
- Source-available for non-commercial testing: optional valve-actuator experiment layer.
- Closed commercial / licensed layer: production hardware files, commercial firmware, and white-label materials.

This project provides controller-board knowledge, sensing logic, and test-bench references. It does not offer valves, plumbing parts, or install work.

This is not a certified home-plumbing safety appliance and not a guarantee against water damage.

## Why This Boundary Exists

The first open layer is straightforward to share widely because it focuses on offline sensing and local alerts on a DIY controller board.

Actuator work is different. Once a project starts moving real hardware in response to water events, the burden of testing, validation, compatibility, and misuse handling becomes much higher.

That is why the repository separates:

- open offline sensing
- restricted non-commercial experiment layers
- closed commercial or production layers

This helps the project stay useful to makers without pretending that every future layer should be unrestricted.
The first release remains fully offline, uses no cloud path, and does not upload household water data.

## Layer 1: Open-Source Offline Sensing and Local Alerting Layer

This layer is intended to be open-source.

Typical items in this layer include:

- leak probe reading
- flow sensor reading
- basic low-flow detection
- buzzer behavior
- local indicator output
- local button handling
- optional local display output
- basic event logging
- demo wiring
- BOM
- test-bench documentation
- safety notes

The goal of this layer is to:

- help makers reproduce the basic detector board
- collect community feedback
- keep the project transparent where broad collaboration helps
- support low-cost offline household water monitoring experiments

## Layer 2: Source-Available Non-Commercial Testing Layer

This layer is **not** standard open-source.

If published, it should be described as:

**source-available for non-commercial testing**

Typical items in this layer may include:

- optional valve-actuator experiment logic
- countdown logic
- manual cancel logic
- maintenance/test mode behavior
- basic multi-signal validation
- low-flow risk evaluation tied to experimental actuator logic
- timeout handling
- test data templates

What is allowed in this layer:

- personal testing
- private modification for personal testing
- community discussion
- non-commercial feedback
- issue reports

What is not allowed in this layer without separate permission:

- commercial resale
- integration into commercial products
- paid install work
- rebranding for profit
- public redistribution of modified restricted-layer code without permission

## Layer 3: Closed Commercial / Licensed Layer

This layer is closed and licensed separately.

Typical items in this layer may include:

- production hardware files
- commercial firmware
- commercial diagnostics tools
- white-label materials
- manufacturing packages
- support tools
- production test procedures

## What Is Allowed

The following are generally allowed within the intended boundary of the project and the license of each released part:

- use the open sensing layer for learning
- build personal prototypes
- submit issues and test results
- fork open-source parts under their published license
- share non-commercial testing feedback
- link to the project

Different folders or modules may be released under different terms. Always check the license notice in that folder or file.

## What Is Not Allowed Without Commercial Permission

The following are not allowed without separate commercial permission where restricted layers are involved:

- selling complete devices based on restricted layers
- using restricted layers in paid products
- using restricted layers for paid install work
- rebranding restricted parts
- claiming certification
- claiming guaranteed water-damage prevention
- using the project name or author identity to market unrelated products

## Safety and Liability Statement

Open Water Guard is a DIY controller-board project and an open detection experiment.

It is:

- not a consumer-ready appliance
- not a certified home-plumbing safety appliance
- not a guarantee against water damage

The open-source sensing layer should remain useful even if any optional actuator experiment layer is never enabled or never used.

Use this project at your own risk.

## Community Test Data Policy

If community members participate in testing, useful feedback may include:

- probe placement
- flow behavior
- false alerts
- low-flow events
- disconnect events
- buzzer behavior
- indicator behavior
- uptime

The project does **not** need:

- home address
- personal identity
- exact daily household water schedule
- private household details

## Commercial Licensing

Commercial collaboration may include:

- commercial firmware licensing
- evaluation kits
- white-label versions
- production hardware files
- custom integration
- small-batch manufacturing support

Specific pricing and commercial terms should be handled separately.
