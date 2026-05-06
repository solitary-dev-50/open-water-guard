#include "alarm/StatusLed.h"

#include <Arduino.h>

#include "pins/BoardPins.h"

namespace owg {

void StatusLed::begin() {
  pinMode(pins::kStatusLed, OUTPUT);
  digitalWrite(pins::kStatusLed, LOW);
}

void StatusLed::setState(LedState state) {
  state_ = state;
  digitalWrite(pins::kStatusLed, state_ == LedState::kNormal ? LOW : HIGH);
}

LedState StatusLed::state() const {
  return state_;
}

}  // namespace owg
