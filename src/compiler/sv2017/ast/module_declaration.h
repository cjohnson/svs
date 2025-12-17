// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <memory>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// A SystemVerilog module declaration.
class ModuleDeclaration : public Description {
 public:
  // Constructs a module declaration with the provided location, header, and
  // optional timeunits declaration.
  ModuleDeclaration(
      const yy::location& location, std::unique_ptr<ModuleHeader> header,
      std::unique_ptr<TimeunitsDeclaration> timeunits_declaration);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The module header
  std::unique_ptr<ModuleHeader> header_;

  // The timeunits declaration (if provided)
  std::unique_ptr<TimeunitsDeclaration> timeunits_declaration_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
