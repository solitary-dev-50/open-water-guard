#pragma once

#include <string>

namespace owg {

struct LeakSensorState {
  std::string id;
  bool enabled = true;
  bool online = true;
  bool wet = false;
};

class LeakSensor {
 public:
  explicit LeakSensor(std::string id);

  void poll();
  const LeakSensorState& state() const;

 private:
  LeakSensorState state_;
};

}  // namespace owg
