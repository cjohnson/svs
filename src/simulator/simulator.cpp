// Copyright (c) 2026 Collin Johnson

#include "simulator/simulator.h"

#include <memory>
#include <queue>

using Simulator = svs::sim::Simulator;

Simulator::Simulator() {}

void Simulator::Run(std::shared_ptr<Module> top_level_module) {
  std::queue<std::shared_ptr<Process>> simulation_queue;

  for (std::shared_ptr<Process> process : top_level_module->initials) {
    simulation_queue.push(process);
  }

  while (!simulation_queue.empty()) {
    std::shared_ptr<Process> process = simulation_queue.front();
    simulation_queue.pop();

    process->Execute();
  }
}
