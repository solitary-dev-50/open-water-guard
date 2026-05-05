#pragma once

#include <cstdint>

namespace owg {

enum class EventType {
  kLeakDetected,
  kLeakRecovered,
  kFlowDetected,
  kLowFlowObserved,
  kPowerFault,
};

struct EventRecord {
  EventType type = EventType::kFlowDetected;
  std::uint32_t timestamp_ms = 0;
};

}  // namespace owg
