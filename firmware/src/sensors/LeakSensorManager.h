#pragma once

#include <vector>

#include "sensors/LeakSensor.h"

namespace owg {

struct LeakSensorSummary {
  bool any_online = false;
  bool any_wet = false;
  std::size_t wet_count = 0;
};

class LeakSensorManager {
 public:
  void begin();
  void poll();

  const std::vector<LeakSensor>& sensors() const;
  LeakSensorSummary summary() const;

 private:
  std::vector<LeakSensor> sensors_{
      LeakSensor("washer"), LeakSensor("heater"), LeakSensor("kitchen")};
};

}  // namespace owg
