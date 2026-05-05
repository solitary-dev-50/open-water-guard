#include "time/TimeUtils.h"

namespace owg {

bool TimeUtils::hasElapsed(
    std::chrono::steady_clock::time_point start,
    std::chrono::steady_clock::duration duration,
    std::chrono::steady_clock::time_point now) {
  return now - start >= duration;
}

std::chrono::steady_clock::duration TimeUtils::remainingDuration(
    std::chrono::steady_clock::time_point start,
    std::chrono::steady_clock::duration duration,
    std::chrono::steady_clock::time_point now) {
  if (hasElapsed(start, duration, now)) {
    return std::chrono::steady_clock::duration::zero();
  }

  return duration - (now - start);
}

}  // namespace owg
