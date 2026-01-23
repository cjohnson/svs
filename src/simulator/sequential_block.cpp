// Copyright (c) 2026 Collin Johnson

#include "simulator/sequential_block.h"

#include <memory>
#include <utility>
#include <vector>

using SequentialBlock = svs::sim::SequentialBlock;

SequentialBlock::SequentialBlock(
    std::vector<std::unique_ptr<Statement>> statements)
    : Statement(), statements_(std::move(statements)) {}

void SequentialBlock::Execute() {
  for (const std::unique_ptr<Statement>& statement : statements_)
    statement->Execute();
}
