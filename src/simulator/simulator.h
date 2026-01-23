// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_SIMULATOR_H_
#define SRC_SIMULATOR_SIMULATOR_H_

#include <memory>
#include <queue>

#include "simulator/statement.h"

namespace svs::sim {

// A simulator
class Simulator {
 public:
  Simulator();

  // Run the simulation.
  void Run();

 private:
  std::queue<std::unique_ptr<Statement>> schedule_;
};

};  // namespace svs::sim

#endif  // SRC_SIMULATOR_SIMULATOR_H_
