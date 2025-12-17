// Copyright (c) 2025 Collin Johnson. All rights reserved.

#include <iostream>
#include <memory>

#include "compiler/sv2017/ast/json_visitor.h"
#include "compiler/sv2017/parser.h"

namespace sv2017 = svs::sv2017;

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "need a file\n";
    return 1;
  }

  sv2017::Parser parser;
  std::unique_ptr<ast::SourceText> ast = parser.Parse(argv[1]);
  assert(ast);

  sv2017::ast::JsonVisitor json_visitor;
  ast->Accept(json_visitor);
  std::cout << json_visitor.result() << '\n';

  return 0;
}
