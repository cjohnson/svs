// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_header.h"

#include <string>

#include <nlohmann/json.hpp>

#include "compiler/sv2017/location.hh"

using json = nlohmann::json;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleHeader::ModuleHeader(const yy::location& location,
                           const std::string& identifier)
    : Node(location), identifier_(identifier) {}

json ModuleHeader::MarshallJson() {
  json j = Node::MarshallJson();
  j["identifier"] = identifier_;

  return j;
}
