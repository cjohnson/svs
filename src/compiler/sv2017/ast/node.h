// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_NODE_H_
#define SRC_COMPILER_SV2017_AST_NODE_H_

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// SystemVerilog 2017 AST node
class Node {
 public:
  // JSON type defined for convenience
  using json = nlohmann::json;

  // Constructs a node with the provided location
  explicit Node(const yy::location& location);

  // Returns the JSON representation of the tree.
  virtual json MarshallJson();

  // Returns the location of the node in the source text.
  const yy::location& location();

 private:
  // The location of the node in the source text.
  yy::location location_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_NODE_H_
