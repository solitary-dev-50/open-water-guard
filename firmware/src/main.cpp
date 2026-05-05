#include <Arduino.h>

#include "alarm/Buzzer.h"
#include "alarm/StatusLed.h"
#include "app/AppController.h"
#include "config/ConfigManager.h"
#include "logs/EventLog.h"
#include "power/PowerManager.h"
#include "rules/RuleEngine.h"
#include "sensors/FlowSensor.h"
#include "sensors/LeakSensorManager.h"

namespace {

owg::Buzzer g_buzzer;
owg::StatusLed g_status_led;
owg::LeakSensorManager g_leak_sensor_manager;
owg::FlowSensor g_flow_sensor;
owg::ConfigManager g_config_manager;
owg::EventLog g_event_log;
owg::PowerManager g_power_manager;
owg::RuleEngine g_rule_engine;

owg::AppController g_app(
    g_buzzer,
    g_status_led,
    g_leak_sensor_manager,
    g_flow_sensor,
    g_config_manager,
    g_event_log,
    g_power_manager,
    g_rule_engine);

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(100);
  g_app.setup();
}

void loop() {
  g_app.loop();
}
