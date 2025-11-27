// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_NODE_H_
#define SRC_COMPILER_SV2017_AST_NODE_H_

#include <string>

namespace svs::sv2017::ast {

//
// SystemVerilog 2017 AST node
//
class Node {
 public:
  //
  // Returns a json representation of the tree.
  //
  virtual std::string to_json(size_t indent_level = 0) = 0;

 protected:
  //
  // Appends indentation and returns the ostream.
  //
  std::ostream& with_indent(std::ostream& os, size_t indent_level);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_NODE_H_
