#include "sensors/FlowSensor.h"

namespace owg {

void FlowSensor::begin() {}

void FlowSensor::poll() {}

FlowSensorSummary FlowSensor::summary() const {
  return summary_;
}

}  // namespace owg
