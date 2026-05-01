// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_EVALUATION_EVENT_H_
#define SRC_SIMULATOR_EVALUATION_EVENT_H_

#include "event.h"

namespace svs::sim {

// A simulation evaluation event.
class EvaluationEvent : public Event {
 public:
  // Executes the evaluation event.
  virtual void Execute();
};

}  // namespace svs::sim

#endif  // SRC_SIMULATOR_EVALUATION_EVENT_H_
