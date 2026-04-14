// Copyright (c) 2026 Collin Johnson

#ifndef SRC_COMPILER_SV2017_VHWD_SOURCE_GENERATOR_H_
#define SRC_COMPILER_SV2017_VHWD_SOURCE_GENERATOR_H_

#include "compiler/sv2017/ast/module_declaration.h"
#include "compiler/sv2017/ast/partial_visitor.h"
#include "compiler/sv2017/ast/source_text.h"
#include "compiler/vhwd/source.h"

namespace svs::sv2017::vhwd {

// Generates VHWD sources for provided SV2017 ASTs.
class SourceGenerator : public ast::PartialVisitor {
 public:
  // Generates VHWD source for a provided SV2017 AST.
  std::unique_ptr<svs::vhwd::Source> Generate(
      std::unique_ptr<ast::SourceText>& source_text);

 private:
  void Visit(sv2017::ast::SourceText& source_text) override;
  void Visit(sv2017::ast::ModuleDeclaration& module_declaration) override;

  std::unique_ptr<svs::vhwd::Source> source_;
};

}  // namespace svs::sv2017::vhwd

#endif  // SRC_COMPILER_SV2017_VHWD_SOURCE_GENERATOR_H_
