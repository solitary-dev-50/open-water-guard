#include "app/AppController.h"

#include <Arduino.h>

#include "logs/EventTypes.h"

namespace owg {

namespace {

constexpr std::uint32_t kStatusPrintIntervalMs = 5000;

const char* ToString(WaterRiskLevel level) {
  switch (level) {
    case WaterRiskLevel::kNormal:
      return "normal";
    case WaterRiskLevel::kWarning:
      return "warning";
    case WaterRiskLevel::kHighRisk:
      return "high-risk";
  }

  return "unknown";
}

}  // namespace

AppController::AppController(
    Buzzer& buzzer,
    StatusLed& status_led,
    LeakSensorManager& leak_sensor_manager,
    FlowSensor& flow_sensor,
    ConfigManager& config_manager,
    EventLog& event_log,
    PowerManager& power_manager,
    RuleEngine& rule_engine)
    : buzzer_(buzzer),
      status_led_(status_led),
      leak_sensor_manager_(leak_sensor_manager),
      flow_sensor_(flow_sensor),
      config_manager_(config_manager),
      event_log_(event_log),
      power_manager_(power_manager),
      rule_engine_(rule_engine) {}

void AppController::setup() {
  buzzer_.begin();
  status_led_.begin();
  leak_sensor_manager_.begin();
  flow_sensor_.begin();
  config_manager_.begin();
  event_log_.begin();
  power_manager_.begin();

  updateDecision();
  updateOutputs();

  Serial.println();
  Serial.println("OWG boot");
  Serial.println("serial ready at 115200");
  emitLoopStatusIfDue();
}

void AppController::loop() {
  pollModules();
  updateDecision();
  updateOutputs();
  emitLoopStatusIfDue();
}

void AppController::pollModules() {
  power_manager_.poll();
  leak_sensor_manager_.poll();
  flow_sensor_.poll();
}

void AppController::updateDecision() {
  RuleInputs inputs{
      leak_sensor_manager_.summary(),
      flow_sensor_.summary(),
      power_manager_.summary(),
      config_manager_.config()};

  current_decision_ = rule_engine_.evaluate(inputs);
}

void AppController::updateOutputs() {
  buzzer_.setAlarmActive(current_decision_.buzzer_requested);
  status_led_.setState(current_decision_.led_state);
}

void AppController::emitLoopStatusIfDue() {
  const std::uint32_t now_ms = millis();

  if (last_status_print_ms_ != 0 &&
      now_ms - last_status_print_ms_ < kStatusPrintIntervalMs) {
    return;
  }

  last_status_print_ms_ = now_ms;

  const LeakSensorSummary leak_summary = leak_sensor_manager_.summary();
  const FlowSensorSummary flow_summary = flow_sensor_.summary();
  const PowerSummary power_summary = power_manager_.summary();

  Serial.print("[owg] uptime_ms=");
  Serial.print(now_ms);
  Serial.print(" risk=");
  Serial.print(ToString(current_decision_.level));
  Serial.print(" leak_wet=");
  Serial.print(leak_summary.wet_count);
  Serial.print(" flow_lpm=");
  Serial.print(flow_summary.liters_per_minute, 2);
  Serial.print(" flow_present=");
  Serial.print(flow_summary.flow_present ? "yes" : "no");
  Serial.print(" main_power=");
  Serial.print(power_summary.main_power_available ? "ok" : "fault");
  Serial.print(" backup_power=");
  Serial.println(power_summary.backup_power_available ? "present" : "missing");
}

}  // namespace owg
