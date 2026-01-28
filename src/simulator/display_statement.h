// Copyright (c) 2026 Collin Johnson

#ifndef SRC_SIMULATOR_DISPLAY_STATEMENT_H_
#define SRC_SIMULATOR_DISPLAY_STATEMENT_H_

#include <string>

#include "simulator/statement.h"

namespace svs::sim {

// A display statement.
class DisplayStatement : public Statement {
 public:
  // Constructs a display statement
  DisplayStatement(std::string format);

  // Execute the statement
  void Execute() override;

 private:
  std::string format_;
};

}  // namespace svs::sim

#endif  // SRC_SIMULATOR_DISPLAY_STATEMENT_H_
