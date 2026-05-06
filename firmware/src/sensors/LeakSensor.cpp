#include "sensors/LeakSensor.h"

#include <Arduino.h>

#include <utility>

namespace owg {

LeakSensor::LeakSensor(std::string id, std::uint8_t pin)
    : pin_(pin) {
  state_.id = std::move(id);
}

void LeakSensor::begin() {
  pinMode(pin_, INPUT_PULLUP);
}

void LeakSensor::poll() {
  state_.online = true;
  state_.wet = state_.enabled && digitalRead(pin_) == LOW;
}

const LeakSensorState& LeakSensor::state() const {
  return state_;
}

}  // namespace owg
