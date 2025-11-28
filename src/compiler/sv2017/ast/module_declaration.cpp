// Copyright (c) 2025 Collin Johnson

#include "module_declaration.h"

#include <memory>
#include <sstream>
#include <string>
#include <utility>

namespace ast = svs::sv2017::ast;

ast::ModuleHeader::ModuleHeader(const std::string& identifier)
  : identifier_(identifier) { }

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

ast::ModuleDeclaration::ModuleDeclaration(
    std::unique_ptr<ModuleHeader> header)
  : header_(std::move(header)) { }

std::string ast::ModuleDeclaration::to_json(size_t indent_level) {
  std::stringstream ss;

  with_indent(ss, indent_level++) << "{\n";
  with_indent(ss, indent_level) << "\"declaration_type\": \"module\",\n";
  with_indent(ss, indent_level) << "\"header\": "
    << header_->to_json(indent_level + 1) << "\n";
  with_indent(ss, --indent_level) << "}";

  return ss.str();
}

