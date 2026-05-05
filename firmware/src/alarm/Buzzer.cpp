#include "alarm/Buzzer.h"

namespace owg {

void Buzzer::begin() {}

void Buzzer::setAlarmActive(bool active) {
  alarm_active_ = active;
}

bool Buzzer::isAlarmActive() const {
  return alarm_active_;
}

}  // namespace owg
