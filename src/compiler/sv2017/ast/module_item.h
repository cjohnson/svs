// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_ITEM_H_
#define SRC_COMPILER_SV2017_AST_MODULE_ITEM_H_

#include "compiler/sv2017/ast/node.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A module item.
class ModuleItem : public Node {
 public:
  // Constructs a module item with the provided location.
  ModuleItem(const yy::location& location);
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_ITEM_H_
