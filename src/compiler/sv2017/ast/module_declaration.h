// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
#define SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_

#include <memory>

#include <nlohmann/json_fwd.hpp>

#include "compiler/sv2017/ast/module_header.h"
#include "compiler/sv2017/ast/description.h"

namespace svs::sv2017::ast {

// A SystemVerilog module declaration.
class ModuleDeclaration : public Description {
 public:
  // Constructs a module declaration.
  // Client passes the module header.
  explicit ModuleDeclaration(std::unique_ptr<ModuleHeader> header);

  // Returns the JSON representation of the tree.
  json MarshallJson() override;

 private:
  // The module header
  std::unique_ptr<ModuleHeader> header_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_MODULE_DECLARATION_H_
