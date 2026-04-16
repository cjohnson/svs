// Copyright (c) 2025 Collin Johnson. All rights reserved.

#include <cstdlib>
#include <iostream>
#include <memory>

#include "compiler/sv2017/json/serializer.h"
#include "compiler/sv2017/parser.h"
#include "compiler/sv2017/vhwd/source_generator.h"
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
    svs::sv2017::vhwd::SourceGenerator vhwd_generator;
    std::unique_ptr<svs::vhwd::Source> source = vhwd_generator.Generate(ast);

    svs::sim::Simulator simulator;

    auto top_level_module = std::make_shared<svs::sim::Module>();
    top_level_module->variables["a"] = svs::sim::TwoValuedValue::_0;

    auto initial = std::make_shared<svs::sim::Process>();
    initial->module = top_level_module;

    auto assign = std::make_shared<svs::sim::AssignmentInstruction>();
    assign->identifier = "a";
    assign->value = svs::sim::TwoValuedValue::_1;

    initial->instructions.push_back(assign);

    auto display = std::make_shared<svs::sim::DisplayInstruction>();
    display->format = "a is %d.";
    display->params.push_back("a");

    initial->instructions.push_back(display);

    top_level_module->initials.insert(initial);

    simulator.Run(top_level_module);

    return EXIT_SUCCESS;
  }

  assert(false);
  return EXIT_FAILURE;
}
