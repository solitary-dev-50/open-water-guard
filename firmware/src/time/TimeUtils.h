#pragma once

#include <chrono>

namespace owg {

class TimeUtils {
 public:
  static bool hasElapsed(
      std::chrono::steady_clock::time_point start,
      std::chrono::steady_clock::duration duration,
      std::chrono::steady_clock::time_point now);

  static std::chrono::steady_clock::duration remainingDuration(
      std::chrono::steady_clock::time_point start,
      std::chrono::steady_clock::duration duration,
      std::chrono::steady_clock::time_point now);
};

}  // namespace owg
