// Copyright (c) 2026 Collin Johnson

#include "simulator/simulator.h"

#include <memory>
#include <queue>
#include <stdexcept>

using Simulator = svs::sim::Simulator;

Simulator::Simulator() {}

void Simulator::Run(std::shared_ptr<Module> top_level_module) {
  finished_ = false;

  std::queue<std::shared_ptr<Process>> simulation_queue;

  for (std::shared_ptr<Process> process : top_level_module->initials) {
    simulation_queue.push(process);
  }

  while (!simulation_queue.empty() && !finished_) {
    std::shared_ptr<Process> process = simulation_queue.front();
    simulation_queue.pop();

    process->Execute();
  }

  std::cout << "\n";
  std::cout << "SVS SIMULATION REPORT\n";
  std::cout << "=====================\n";
  std::cout << "...\n\n";
}

svs::sim::TwoValuedValue Simulator::GetVariable(std::string identifier) {
  throw std::runtime_error{"Failed to find variable"};
}

void Simulator::SetVariable(std::string identifier, TwoValuedValue value) {
  throw std::runtime_error{"Failed to find variable"};
}

void Simulator::Finish() { finished_ = true; }
