#include "logs/EventLog.h"

namespace owg {

void EventLog::begin() {}

void EventLog::append(const EventRecord& record) {
  records_.push_back(record);
}

const std::vector<EventRecord>& EventLog::records() const {
  return records_;
}

}  // namespace owg
