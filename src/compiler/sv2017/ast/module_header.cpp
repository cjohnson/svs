// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_header.h"

#include <nlohmann/json.hpp>
#include <string>

#include "compiler/sv2017/ast/visitor.h"
#include "compiler/sv2017/location.hh"

using json = nlohmann::json;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleHeader::ModuleHeader(const yy::location& location,
                           const std::string& identifier)
    : Node(location), identifier_(identifier) {}

void ModuleHeader::Accept(Visitor& visitor) { visitor.Visit(*this); }

json ModuleHeader::MarshallJson() {
  json j = Node::MarshallJson();
  j["identifier"] = identifier_;

  return j;
}
