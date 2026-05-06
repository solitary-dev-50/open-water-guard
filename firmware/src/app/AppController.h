#pragma once

#include <cstdint>

#include "alarm/Buzzer.h"
#include "alarm/StatusLed.h"
#include "config/ConfigManager.h"
#include "controls/LocalButtons.h"
#include "logs/EventLog.h"
#include "power/PowerManager.h"
#include "rules/RuleEngine.h"
#include "sensors/FlowSensor.h"
#include "sensors/LeakSensorManager.h"

namespace owg {

class AppController {
 public:
  AppController(
      Buzzer& buzzer,
      StatusLed& status_led,
      LocalButtons& local_buttons,
      LeakSensorManager& leak_sensor_manager,
      FlowSensor& flow_sensor,
      ConfigManager& config_manager,
      EventLog& event_log,
      PowerManager& power_manager,
      RuleEngine& rule_engine);

  void setup();
  void loop();

 private:
  void pollModules();
  void updateDecision();
  void updateOutputs();
  void emitLoopStatusIfDue();

  Buzzer& buzzer_;
  StatusLed& status_led_;
  LocalButtons& local_buttons_;
  LeakSensorManager& leak_sensor_manager_;
  FlowSensor& flow_sensor_;
  ConfigManager& config_manager_;
  EventLog& event_log_;
  PowerManager& power_manager_;
  RuleEngine& rule_engine_;
  WaterRiskDecision current_decision_;
  bool alarm_muted_ = false;
  std::uint32_t last_status_print_ms_ = 0;
};

}  // namespace owg
