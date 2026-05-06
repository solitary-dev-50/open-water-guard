#pragma once

#include <cstdint>

namespace owg::pins {

constexpr std::uint8_t kLeakProbeWasher = 4;
constexpr std::uint8_t kLeakProbeHeater = 5;
constexpr std::uint8_t kLeakProbeKitchen = 6;

constexpr std::uint8_t kFlowPulse = 7;

constexpr std::uint8_t kBuzzer = 15;
constexpr std::uint8_t kStatusLed = 16;

constexpr std::uint8_t kMuteButton = 17;
constexpr std::uint8_t kAcknowledgeButton = 18;

}  // namespace owg::pins
