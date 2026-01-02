// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <memory>
#include <vector>

#include "compiler/sv2017/ast/continuous_assign.h"
#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A SystemVerilog module declaration.
class ModuleDeclaration : public Description {
 public:
  // Constructs a module declaration with the provided location, header,
  // optional timeunits declaration, and items.
  ModuleDeclaration(const yy::location& location,
                    std::unique_ptr<ModuleHeader> header,
                    std::unique_ptr<TimeunitsDeclaration> timeunits_declaration,
                    std::vector<std::unique_ptr<ContinuousAssign>> items);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The module header
  const std::unique_ptr<ModuleHeader>& header();

  // The timeunits declaration (if provided)
  const std::unique_ptr<TimeunitsDeclaration>& timeunits_declaration();

  // The items
  inline const std::vector<std::unique_ptr<ContinuousAssign>>& items() {
    return items_;
  }

 private:
  std::unique_ptr<ModuleHeader> header_;
  std::unique_ptr<TimeunitsDeclaration> timeunits_declaration_;
  std::vector<std::unique_ptr<ContinuousAssign>> items_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
