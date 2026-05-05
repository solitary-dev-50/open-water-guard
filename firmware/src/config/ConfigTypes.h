#pragma once

#include <cstdint>

namespace owg {

struct DeviceConfig {
  std::uint32_t low_flow_observe_minutes = 15;
  std::uint32_t low_flow_warning_minutes = 60;
  std::uint32_t low_flow_high_risk_minutes = 120;
};

}  // namespace owg
