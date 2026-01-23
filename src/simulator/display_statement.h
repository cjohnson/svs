// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_DISPLAY_STATEMENT_H_
#define SRC_SIMULATOR_DISPLAY_STATEMENT_H_

#include "simulator/statement.h"

namespace svs::sim {

// A display statement.
class DisplayStatement : public Statement {
 public:
  // Constructs a display statement
  DisplayStatement();

  // Execute the statement
  void Execute() override;
};

}  // namespace svs::sim

#endif  // SRC_SIMULATOR_DISPLAY_STATEMENT_H_
