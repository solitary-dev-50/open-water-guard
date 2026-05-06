#include "alarm/Buzzer.h"

#include <Arduino.h>

#include "pins/BoardPins.h"

namespace owg {

void Buzzer::begin() {
  pinMode(pins::kBuzzer, OUTPUT);
  digitalWrite(pins::kBuzzer, LOW);
}

void Buzzer::setAlarmActive(bool active) {
  alarm_active_ = active;
  digitalWrite(pins::kBuzzer, alarm_active_ ? HIGH : LOW);
}

bool Buzzer::isAlarmActive() const {
  return alarm_active_;
}

}  // namespace owg
