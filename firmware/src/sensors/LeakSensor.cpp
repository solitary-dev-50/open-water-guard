#include "sensors/LeakSensor.h"

#include <utility>

namespace owg {

LeakSensor::LeakSensor(std::string id) {
  state_.id = std::move(id);
}

void LeakSensor::poll() {}

const LeakSensorState& LeakSensor::state() const {
  return state_;
}

}  // namespace owg
