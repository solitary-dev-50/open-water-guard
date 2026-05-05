#pragma once

namespace owg {

struct PowerSummary {
  bool main_power_available = true;
  bool backup_power_available = false;
  bool backup_power_low = false;
};

class PowerManager {
 public:
  void begin();
  void poll();
  PowerSummary summary() const;

 private:
  PowerSummary summary_;
};

}  // namespace owg
