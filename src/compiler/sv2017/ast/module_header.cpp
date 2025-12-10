// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/ast/module_header.h"

#include <string>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using ModuleHeader = svs::sv2017::ast::ModuleHeader;

ModuleHeader::ModuleHeader(const std::string& identifier)
    : identifier_(identifier) {}

json ModuleHeader::MarshallJson() {
  json j;
  j["identifier"] = identifier_;

  return j;
}
