#include "rules/RuleEngine.h"

namespace owg {

WaterRiskDecision RuleEngine::evaluate(const RuleInputs& inputs) const {
  if (inputs.leak_summary.any_wet) {
    WaterRiskDecision decision;
    decision.level = WaterRiskLevel::kHighRisk;
    decision.led_state = LedState::kAlarm;
    decision.buzzer_requested = true;
    return decision;
  }

  if (!inputs.power_summary.main_power_available) {
    WaterRiskDecision decision;
    decision.level = WaterRiskLevel::kWarning;
    decision.led_state = LedState::kPowerFault;
    decision.buzzer_requested = true;
    return decision;
  }

  if (inputs.flow_summary.flow_present) {
    WaterRiskDecision decision;
    decision.level = WaterRiskLevel::kWarning;
    decision.led_state = LedState::kWarning;
    return decision;
  }

  return {};
}

}  // namespace owg
