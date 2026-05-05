#include "alarm/StatusLed.h"

namespace owg {

void StatusLed::begin() {}

void StatusLed::setState(LedState state) {
  state_ = state;
}

LedState StatusLed::state() const {
  return state_;
}

}  // namespace owg
