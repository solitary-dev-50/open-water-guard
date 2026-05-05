#pragma once

#include <vector>

#include "logs/EventTypes.h"

namespace owg {

class EventLog {
 public:
  void begin();
  void append(const EventRecord& record);
  const std::vector<EventRecord>& records() const;

 private:
  std::vector<EventRecord> records_;
};

}  // namespace owg
