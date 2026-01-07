// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_
#define SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_

#include "compiler/sv2017/ast/module_item.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An initial construct.
class InitialConstruct : public ModuleItem {
 public:
  // Constructs an initial construct with the provided location.
  InitialConstruct(const yy::location& location);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_
