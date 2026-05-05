#pragma once

#include "config/ConfigTypes.h"

namespace owg {

class ConfigManager {
 public:
  void begin();
  const DeviceConfig& config() const;
  bool validate(const DeviceConfig& config) const;

 private:
  DeviceConfig config_;
};

}  // namespace owg
