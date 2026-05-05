#pragma once

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
  FlowSensorSummary summary_;
};

}  // namespace owg
