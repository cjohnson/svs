// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_
#define SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_

#include <memory>

#include "compiler/sv2017/ast/module_item.h"
#include "compiler/sv2017/ast/statement.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// An initial construct.
class InitialConstruct : public ModuleItem {
 public:
  // Constructs an initial construct with the provided location and statement.
  InitialConstruct(const yy::location& location,
                   std::unique_ptr<Statement> statement);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  inline const std::unique_ptr<Statement>& statement() { return statement_; }

 private:
  std::unique_ptr<Statement> statement_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_INITIAL_CONSTRUCT_H_
