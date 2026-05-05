#pragma once

#include "config/ConfigTypes.h"
#include "power/PowerManager.h"
#include "rules/WaterRiskState.h"
#include "sensors/FlowSensor.h"
#include "sensors/LeakSensorManager.h"

namespace owg {

struct RuleInputs {
  LeakSensorSummary leak_summary;
  FlowSensorSummary flow_summary;
  PowerSummary power_summary;
  DeviceConfig config;
};

class RuleEngine {
 public:
  WaterRiskDecision evaluate(const RuleInputs& inputs) const;
};

}  // namespace owg
