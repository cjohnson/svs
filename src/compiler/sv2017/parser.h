// Copyright (c) 2025 Collin Johnson

#ifndef SRC_COMPILER_SV2017_PARSER_H_
#define SRC_COMPILER_SV2017_PARSER_H_

#include <memory>
#include <string>

#include "compiler/sv2017/ast/source_text.h"
#include "compiler/sv2017/parser.generated.h"

#define YY_DECL yy::parser::symbol_type yylex(svs::sv2017::Parser& parser)

namespace svs::sv2017 {

// Parser class for SystemVerilog 2017.
//
// Bison generates a class, yy::parser, that performs the parsing
// for the context-free grammar defined in parser.y. This class
// provides a C++ interface that returns the tree pointer when
// calling Parse.
class Parser {
 public:
  // Runs the parser on a source file.
  // Client provides the file name for the file.
  std::unique_ptr<ast::SourceText> Parse(const std::string& file_name);

  // The location variable that yy::parser will use while parsing.
  yy::location location_;

 private:
  // Sets up the scanner to scan a source file.
  // Caller provides the name of the source file.
  void BeginScan(const std::string& file_name);

  // Ends the scan.
  void EndScan();

  // The location where the parsing implementation class will place
  // the final result.
  std::unique_ptr<ast::SourceText> result_ = nullptr;

  // If true, the parser will generate parsing debug traces.
  bool parsing_debug_traces_enabled_ = false;

  // If true, the parser will generate scanning debug traces.
  bool scanning_debug_traces_enabled_ = false;

  friend yy::parser;
};

}  // namespace svs::sv2017

YY_DECL;

#endif  // SRC_COMPILER_SV2017_PARSER_H_
