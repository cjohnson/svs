// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/source_text.h"

#include <memory>
#include <nlohmann/json.hpp>
#include <utility>
#include <vector>

#include "compiler/sv2017/ast/description.h"
#include "compiler/sv2017/ast/visitor.h"

using json = nlohmann::json;
using SourceText = svs::sv2017::ast::SourceText;

SourceText::SourceText(
    const yy::location& location,
    std::unique_ptr<TimeunitsDeclaration> timeunits_declaration,
    std::vector<std::unique_ptr<Description>> descriptions)
    : Node(location),
      timeunits_declaration_(std::move(timeunits_declaration)),
      descriptions_(std::move(descriptions)) {}

void SourceText::Accept(Visitor& visitor) { visitor.Visit(*this); }

json SourceText::MarshallJson() {
  json j = Node::MarshallJson();

  j["_type"] = "source_text";
  j["_version"] = 2017;

  std::vector<json> descriptions_json;
  descriptions_json.reserve(descriptions_.size());
  for (const std::unique_ptr<Description>& description : descriptions_)
    descriptions_json.emplace_back(description->MarshallJson());
  j["descriptions"] = descriptions_json;

  if (timeunits_declaration_)
    j["timeunits_declaration"] = timeunits_declaration_->MarshallJson();

  return j;
}
