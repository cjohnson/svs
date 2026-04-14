// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_VHWD_MODULE_GENERATOR_H_
#define SRC_COMPILER_SV2017_VHWD_MODULE_GENERATOR_H_

#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/partial_visitor.h"
#include "compiler/vhwd/module.h"

namespace svs::sv2017::vhwd {

// Generates VHWD modules for provided SV2017 module declarations.
class ModuleGenerator : public ast::PartialVisitor {
 public:
  // Generates a VHWD module for the provided SV2017 module declaration.
  std::unique_ptr<svs::vhwd::Module> Generate(
      ast::ModuleDeclaration& module_declaration);

 private:
  void Visit(sv2017::ast::ModuleDeclaration& module_declaration) override;

  std::unique_ptr<svs::vhwd::Module> module_;
};

}  // namespace svs::sv2017::vhwd

#endif  // SRC_COMPILER_SV2017_VHWD_MODULE_GENERATOR_H_
