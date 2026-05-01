// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_EVENT_H_
#define SRC_SIMULATOR_EVENT_H_

namespace svs::sim {

// A simulation event.
class Event {
 public:
  // Executes the event.
  virtual void Execute() = 0;
};

}  // namespace svs::sim

#endif  //  SRC_SIMULATOR_EVENT_H_
