// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_DATA_TYPE_H_
#define SRC_COMPILER_SV2017_AST_DATA_TYPE_H_

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// Data type
class DataType : public Node {
 public:
  // Constructs a data type with the provided location.
  DataType(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_DATA_TYPE_H_
