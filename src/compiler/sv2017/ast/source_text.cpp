// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/source_text.h"

#include <memory>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/ast/description.h"

using json = nlohmann::json;
using SourceText = svs::sv2017::ast::SourceText;

SourceText::SourceText(const yy::location& location,
                       std::vector<std::unique_ptr<Description>> descriptions)
    : Node(location), descriptions_(std::move(descriptions)) {}

json SourceText::MarshallJson() {
  json j = Node::MarshallJson();

  j["_type"] = "source_text";
  j["_version"] = 2017;

  std::vector<json> descriptions_json;
  descriptions_json.reserve(descriptions_.size());
  for (const std::unique_ptr<Description>& description : descriptions_)
    descriptions_json.emplace_back(description->MarshallJson());
  j["descriptions"] = descriptions_json;

  return j;
}
