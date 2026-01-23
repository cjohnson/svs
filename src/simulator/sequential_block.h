// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_SEQUENTIAL_BLOCK_H_
#define SRC_SIMULATOR_SEQUENTIAL_BLOCK_H_

#include <memory>
#include <vector>

#include "simulator/statement.h"

namespace svs::sim {

// A simulator sequential block statement.
class SequentialBlock : public Statement {
 public:
  // Constructs a simulator statement.
  SequentialBlock(std::vector<std::unique_ptr<Statement>> statements);

  // Execute the statement
  void Execute() override;

 private:
  std::vector<std::unique_ptr<Statement>> statements_;
};

}  // namespace svs::sim

#endif  // SRC_SIMULATOR_SEQUENTIAL_BLOCK_H_
