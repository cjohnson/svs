// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_NODE_H_
#define SRC_COMPILER_SV2017_AST_NODE_H_

#include <nlohmann/json_fwd.hpp>

namespace svs::sv2017::ast {

// SystemVerilog 2017 AST node
class Node {
 public:
  // JSON type defined for convenience
  using json = nlohmann::json;

  // Returns the JSON representation of the tree.
  virtual json MarshallJson() = 0;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_NODE_H_
