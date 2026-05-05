#pragma once

namespace owg {

class Buzzer {
 public:
  void begin();
  void setAlarmActive(bool active);
  bool isAlarmActive() const;

 private:
  bool alarm_active_ = false;
};

}  // namespace owg
