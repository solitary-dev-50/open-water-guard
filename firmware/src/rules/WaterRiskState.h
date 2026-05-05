#pragma once

#include "alarm/StatusLed.h"

namespace owg {

enum class WaterRiskLevel {
  kNormal,
  kWarning,
  kHighRisk,
};

struct WaterRiskDecision {
  WaterRiskLevel level = WaterRiskLevel::kNormal;
  LedState led_state = LedState::kNormal;
  bool buzzer_requested = false;
};

}  // namespace owg
