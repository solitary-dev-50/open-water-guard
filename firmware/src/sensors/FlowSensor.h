#pragma once

#include <cstdint>

namespace owg {

struct FlowSensorSummary {
  bool online = true;
  bool flow_present = false;
  bool low_flow_present = false;
  float liters_per_minute = 0.0f;
};

class FlowSensor {
 public:
  void begin();
  void poll();
  FlowSensorSummary summary() const;

 private:
  static void handlePulseInterrupt();

  FlowSensorSummary summary_;
  std::uint32_t last_sample_ms_ = 0;
  std::uint32_t last_pulse_count_ = 0;
};

}  // namespace owg
