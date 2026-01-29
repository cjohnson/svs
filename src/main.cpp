// Copyright (c) 2025 Collin Johnson. All rights reserved.

#include <cstdlib>
#include <iostream>
#include <memory>

#include "compiler/sv2017/json/serializer.h"
#include "compiler/sv2017/parser.h"
#include "simulator/simulator.h"

void print_usage(std::ostream& os) {
  os << "Usage:";
  os << " - svs --simulate <file.sv>";
  os << " - svs --print-ast <file.sv>";
}

int main(int argc, char** argv) {
  if (argc < 3) {
    print_usage(std::cerr);
    return EXIT_FAILURE;
  }

  std::string command = argv[1];
  if (command != "--simulate" && command != "--print-ast") {
    print_usage(std::cerr);
    return EXIT_FAILURE;
  }

  std::string filename = argv[2];

  svs::sv2017::Parser parser;
  std::unique_ptr<ast::SourceText> ast = parser.Parse(filename);
  if (!ast) {
    std::cerr << "Failed to parse the provided source file.\n";
    return EXIT_FAILURE;
  }

  if (command == "--print-ast") {
    svs::sv2017::json::Serializer json_serializer;
    std::cout << json_serializer.Serialize(*ast) << '\n';

    return EXIT_SUCCESS;
  }

  if (command == "--simulate") {
    svs::sim::Simulator simulator{std::move(ast), "tb"};
    simulator.Run();

    return EXIT_SUCCESS;
  }

  assert(false);
  return EXIT_FAILURE;
}
