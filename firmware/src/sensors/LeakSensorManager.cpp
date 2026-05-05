#include "sensors/LeakSensorManager.h"

namespace owg {

void LeakSensorManager::begin() {}

void LeakSensorManager::poll() {
  for (auto& sensor : sensors_) {
    sensor.poll();
  }
}

const std::vector<LeakSensor>& LeakSensorManager::sensors() const {
  return sensors_;
}

LeakSensorSummary LeakSensorManager::summary() const {
  LeakSensorSummary result;

  for (const auto& sensor : sensors_) {
    const auto& state = sensor.state();
    result.any_online = result.any_online || state.online;
    result.any_wet = result.any_wet || state.wet;
    if (state.wet) {
      ++result.wet_count;
    }
  }

  return result;
}

}  // namespace owg
