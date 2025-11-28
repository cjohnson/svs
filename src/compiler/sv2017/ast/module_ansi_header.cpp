// Copyright (c) 2025 Collin Johnson

#include "module_ansi_header.h"

#include <sstream>
#include <string>

namespace ast = svs::sv2017::ast;

ast::ModuleAnsiHeader::ModuleAnsiHeader(const std::string& identifier)
  : ast::ModuleHeader(identifier) { }

std::string ast::ModuleAnsiHeader::to_json(size_t indent_level) {
  std::stringstream ss;

  ss << "{\n";
  with_indent(ss, indent_level) << "\"identifier\": \""
    << identifier_ << "\"\n";
  with_indent(ss, --indent_level) << "}";

  return ss.str();
}

