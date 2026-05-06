#include "controls/LocalButtons.h"

#include <Arduino.h>

#include "pins/BoardPins.h"

namespace owg {

void LocalButtons::begin() {
  pinMode(pins::kMuteButton, INPUT_PULLUP);
  pinMode(pins::kAcknowledgeButton, INPUT_PULLUP);
}

void LocalButtons::poll() {
  summary_.mute_pressed = readActiveLow(pins::kMuteButton);
  summary_.acknowledge_pressed = readActiveLow(pins::kAcknowledgeButton);
}

ButtonSummary LocalButtons::summary() const {
  return summary_;
}

bool LocalButtons::readActiveLow(std::uint8_t pin) const {
  return digitalRead(pin) == LOW;
}

}  // namespace owg
