#pragma once

#include <cstdint>
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
  LeakSensor(std::string id, std::uint8_t pin);

  void begin();
  void poll();
  const LeakSensorState& state() const;

 private:
  LeakSensorState state_;
  std::uint8_t pin_;
};

}  // namespace owg
