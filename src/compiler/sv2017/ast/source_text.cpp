// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/source_text.h"

#include <memory>
#include <utility>
#include <vector>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/visitor.h"

using Description = svs::sv2017::ast::Description;
using SourceText = svs::sv2017::ast::SourceText;
using TimeunitsDeclaration = svs::sv2017::ast::TimeunitsDeclaration;

SourceText::SourceText(
    const yy::location& location,
    std::unique_ptr<TimeunitsDeclaration> timeunits_declaration,
    std::vector<std::unique_ptr<Description>> descriptions)
    : Node(location),
      timeunits_declaration_(std::move(timeunits_declaration)),
      descriptions_(std::move(descriptions)) {}

void SourceText::Accept(Visitor& visitor) { visitor.Visit(*this); }

const std::unique_ptr<TimeunitsDeclaration>&
SourceText::timeunits_declaration() {
  return timeunits_declaration_;
}

const std::vector<std::unique_ptr<Description>>& SourceText::descriptions() {
  return descriptions_;
}
