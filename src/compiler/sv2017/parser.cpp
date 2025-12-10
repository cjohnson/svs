// Copyright (c) 2025 Collin Johnson

#include "compiler/sv2017/parser.h"

#include <memory>
#include <string>
#include <utility>

using Parser = svs::sv2017::Parser;

std::unique_ptr<ast::SourceText> Parser::Parse(const std::string& file_name) {
  location_.initialize(&file_name);

  BeginScan(file_name);

  yy::parser parser(*this);
  parser.set_debug_level(parsing_debug_traces_enabled_);
  parser.parse();

  EndScan();

  return std::move(result_);
}
