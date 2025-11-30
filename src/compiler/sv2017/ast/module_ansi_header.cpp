// Copyright (c) 2025 Collin Johnson

#include "module_ansi_header.h"

#include <sstream>
#include <string>

namespace ast = svs::sv2017::ast;

ast::ModuleAnsiHeader::ModuleAnsiHeader(
    const std::string& identifier,
    std::vector<std::unique_ptr<AnsiPortDeclaration>> ports)
  : ast::ModuleHeader(identifier),
    ports_(std::move(ports)) { }

std::string ast::ModuleAnsiHeader::to_json(size_t indent_level) {
  std::stringstream ss;

  ss << "{\n";
  with_indent(ss, indent_level) << "\"identifier\": \""
    << identifier_ << "\"\n";
  with_indent(ss, --indent_level) << "}";

  return ss.str();
}

