#include "config/ConfigManager.h"

namespace owg {

void ConfigManager::begin() {}

const DeviceConfig& ConfigManager::config() const {
  return config_;
}

bool ConfigManager::validate(const DeviceConfig& config) const {
  return config.low_flow_observe_minutes > 0 &&
         config.low_flow_warning_minutes >= config.low_flow_observe_minutes &&
         config.low_flow_high_risk_minutes >= config.low_flow_warning_minutes;
}

}  // namespace owg
