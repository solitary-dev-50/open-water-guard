#pragma once

namespace owg {

enum class LedState {
  kNormal,
  kWarning,
  kAlarm,
  kMaintenance,
  kPowerFault,
};

class StatusLed {
 public:
  void begin();
  void setState(LedState state);
  LedState state() const;

 private:
  LedState state_ = LedState::kNormal;
};

}  // namespace owg
