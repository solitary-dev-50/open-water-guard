#pragma once

#include <cstdint>

namespace owg {

struct ButtonSummary {
  bool mute_pressed = false;
  bool acknowledge_pressed = false;
};

class LocalButtons {
 public:
  void begin();
  void poll();
  ButtonSummary summary() const;

 private:
  bool readActiveLow(std::uint8_t pin) const;

  ButtonSummary summary_;
};

}  // namespace owg
