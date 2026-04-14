// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/vhwd/module_generator.h"

#include <memory>

#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/vhwd/module.h"

using ModuleGenerator = svs::sv2017::vhwd::ModuleGenerator;

std::unique_ptr<svs::vhwd::Module> ModuleGenerator::Generate(
    ast::ModuleDeclaration& source_text) {
  module_ = std::make_unique<svs::vhwd::Module>();

  source_text.Accept(*this);

  return std::move(module_);
}

void ModuleGenerator::Visit(
    sv2017::ast::ModuleDeclaration& module_declaration) {
  module_->identifier = module_declaration.header()->identifier();
}
