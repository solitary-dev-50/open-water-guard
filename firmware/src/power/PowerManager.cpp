#include "power/PowerManager.h"

namespace owg {

void PowerManager::begin() {}

void PowerManager::poll() {}

PowerSummary PowerManager::summary() const {
  return summary_;
}

}  // namespace owg
