// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_NODE_H_
#define SRC_COMPILER_SV2017_AST_NODE_H_

#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// Forward declaration of AST visitor
class Visitor;

// SystemVerilog 2017 AST node
class Node {
 public:
  // Constructs a node with the provided location
  explicit Node(const yy::location& location);

  // Virtual destructor declaration
  virtual ~Node() = default;

  // Accept the provided visitor.
  virtual void Accept(Visitor& visitor) = 0;

  // Returns the location of the node in the source text.
  const yy::location& location();

 private:
  // The location of the node in the source text.
  yy::location location_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_NODE_H_
