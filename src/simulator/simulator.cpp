// Copyright (c) 2026 Collin Johnson

#include "simulator/simulator.h"

#include <memory>

#include "simulator/display_statement.h"
#include "simulator/sequential_block.h"

using Simulator = svs::sim::Simulator;

Simulator::Simulator() {
  std::vector<std::unique_ptr<Statement>> sequential_block_schedule;
  sequential_block_schedule.reserve(1);
  sequential_block_schedule.push_back(std::make_unique<DisplayStatement>());

  auto sequential_block =
      std::make_unique<SequentialBlock>(std::move(sequential_block_schedule));
  schedule_.push(std::move(sequential_block));
}

void Simulator::Run() {
  while (!schedule_.empty()) {
    std::unique_ptr<Statement> statement = std::move(schedule_.front());
    schedule_.pop();

    statement->Execute();
  }
}
