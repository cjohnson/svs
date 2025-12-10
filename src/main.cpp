// Copyright (c) 2025 Collin Johnson. All rights reserved.

#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>

#include "compiler/sv2017/parser.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "need a file\n";
    return 1;
  }

  svs::sv2017::Parser parser;

  std::unique_ptr<ast::SourceText> ast = parser.Parse(argv[1]);
  if (ast) std::cout << ast->MarshallJson().dump(2) << '\n';

  return 0;
}
