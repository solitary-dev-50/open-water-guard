# Open Water Guard

Open Water Guard is an offline DIY water monitoring controller board for leak probes, flow sensors, buzzers, buttons, indicators, and optional display output. It does not connect to the internet, uses no cloud path, and does not upload household water data.

## What This First Release Is

The first public release focuses on:

- leak sensing
- flow sensing
- basic low-flow detection
- local buzzer alerts
- buttons for mute and acknowledgement
- indicator outputs
- optional display output

This first release is for **sensing and local alerting only**.

## What This Project Is Not

Open Water Guard is:

- fully offline
- not connected to the internet
- no cloud path
- not uploading data
- a DIY controller board project
- not a consumer-ready appliance
- not a certified home-plumbing safety appliance

Open Water Guard does **not** offer:

- valves
- plumbing parts
- install work

## Project Scope

The current open detection layer is meant to help makers build and test a local water-monitoring board with:

- leak probes
- flow sensors
- buzzer output
- buttons
- indicators
- optional display output

The goal is simple: detect local water-related events and warn the user locally without relying on network infrastructure.

## Offline by Design

Open Water Guard is simply offline.

- no internet connection
- no cloud path
- no mobile app dependency
- no server dependency
- no household data upload

All sensing, evaluation, and local alerts are intended to run on the board itself.

## Important Boundary

This repository currently focuses on the **open sensing and local alerting layer**.

It does not present itself as:

- an automatic valve appliance
- a finished anti-leak appliance
- an online smart-home platform
- a plumbing contractor business

If future experimental actuator work appears, it will be treated as a separate and more restricted layer.

## First-Version Hardware Direction

The first-version controller board knowledge base currently centers around:

- ESP32 / ESP32-S3 controller board
- leak probes
- flow sensor input
- buzzer
- buttons
- indicator outputs
- optional display
- power module
- wiring for a desktop water test bench

Valve actuators are not part of the first required build. They belong only to a future optional experiment layer.

## Safety Position

This project is for DIY board-level experimentation and documentation.

It does not promise:

- certified protection
- insurance-grade loss prevention
- avoidance of all water damage

Users should test in a safe desktop water loop before deciding how to integrate the controller board into their own setup.

## Documentation

- Policy boundary: [docs/open-source-boundary.md](docs/open-source-boundary.md)
- Detection architecture: [docs/detection-architecture.md](docs/detection-architecture.md)
- Low-flow notes: [docs/low-flow-detection.md](docs/low-flow-detection.md)
- Desktop test bench: [docs/test-bench.md](docs/test-bench.md)
- Safety notes: [docs/safety-notes.md](docs/safety-notes.md)
- BOM: [BOM.md](BOM.md)
- Chinese internal notes: [DOC/00-知识库索引.md](DOC/00-知识库索引.md)

## License

Open Water Guard uses a layered licensing model:

- Open sensing and local alerting code: Apache License 2.0.
- Documentation, diagrams, photos, tutorials, and test-bench materials: CC BY-NC 4.0.
- Optional valve-actuator experiment materials, production firmware, production PCB files, white-label materials, and commercial support tools are not covered by the open code license and may use separate terms.

See:

- [LICENSE](LICENSE)
- [LICENSE-DOCS.md](LICENSE-DOCS.md)
- [LICENSE-BOUNDARY.md](LICENSE-BOUNDARY.md)
- [docs/open-source-boundary.md](docs/open-source-boundary.md)

## Support Development

This is an independent DIY open hardware project.

If you find it useful, you can support future sensors, PCB revisions, test fixtures, desktop water-loop experiments, and documentation work here:

- Ko-fi: https://ko-fi.com/solitarydev50

This is not a product pre-order. Contributions help fund parts, testing, and open documentation.
