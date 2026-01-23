// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_STATEMENT_H_
#define SRC_SIMULATOR_STATEMENT_H_

namespace svs::sim {

// A simulator statement.
class Statement {
 public:
  // Constructs a simulator statement.
  Statement();

  // Execute the statement
  virtual void Execute() = 0;
};

}  // namespace svs::sim

#endif  // SRC_SIMULATOR_STATEMENT_H_
