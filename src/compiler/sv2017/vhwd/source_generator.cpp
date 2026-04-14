// Copyright (c) 2026 Collin Johnson

#include "compiler/sv2017/vhwd/source_generator.h"

#include <memory>

#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/vhwd/module_generator.h"
#include "compiler/vhwd/source.h"

using SourceGenerator = svs::sv2017::vhwd::SourceGenerator;

std::unique_ptr<svs::vhwd::Source> SourceGenerator::Generate(
    std::unique_ptr<ast::SourceText>& source_text) {
  source_ = std::make_unique<svs::vhwd::Source>();

  source_text->Accept(*this);

  return std::move(source_);
}

void SourceGenerator::Visit(sv2017::ast::SourceText& source_text) {
  for (const std::unique_ptr<ast::Description>& description :
       source_text.descriptions())
    description->Accept(*this);
}

void SourceGenerator::Visit(
    sv2017::ast::ModuleDeclaration& module_declaration) {
  ModuleGenerator generator;
  std::unique_ptr<svs::vhwd::Module> module =
      generator.Generate(module_declaration);

  source_->modules[module->identifier] = std::move(module);
}
