// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_CONTINUOUS_ASSIGN_H_
#define SRC_COMPILER_SV2017_AST_CONTINUOUS_ASSIGN_H_

#include <vector>

#include "compiler/sv2017/ast/net_assignment.h"
#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A list of continuous assignments.
class ContinuousAssign : public Node {
 public:
  // Constructs a continuous assignment with the provided location and net
  // assignments.
  ContinuousAssign(const yy::location& location,
                   std::vector<std::unique_ptr<NetAssignment>> net_assignments);

  // Accepts the provided visitor.
  void Accept(Visitor& visitor) override;

  // The list of net assignments.
  inline const std::vector<std::unique_ptr<NetAssignment>>& net_assignments() {
    return net_assignments_;
  }

 private:
  std::vector<std::unique_ptr<NetAssignment>> net_assignments_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_CONTINUOUS_ASSIGN_H_
