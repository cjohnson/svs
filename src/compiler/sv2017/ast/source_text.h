// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
#define SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_

#include <memory>
#include <vector>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/timeunits_declaration.h"
#include "compiler/sv2017/location.hh"

namespace svs::sv2017::ast {

// SystemVerilog 2017 source text AST node
class SourceText : public Node {
 public:
  // Constructs a source text with the provided location, timeunits declaration,
  // and descriptions
  SourceText(const yy::location& location,
             std::unique_ptr<TimeunitsDeclaration> timeunits_declaration,
             std::vector<std::unique_ptr<Description>> descriptions);

  // Accept the provided visitor.
  void Accept(Visitor& visitor) override;

  // The timeunits declaration. Can be nullptr if the designer did not provide a
  // timeunits declaration.
  const std::unique_ptr<TimeunitsDeclaration>& timeunits_declaration();

  // The list of descriptions
  const std::vector<std::unique_ptr<Description>>& descriptions();

 private:
  std::unique_ptr<TimeunitsDeclaration> timeunits_declaration_;
  std::vector<std::unique_ptr<Description>> descriptions_;
};

}  // namespace svs::sv2017::ast

#endif  // SRC_COMPILER_SV2017_AST_SOURCE_TEXT_H_
