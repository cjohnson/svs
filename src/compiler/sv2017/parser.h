#ifndef SVS_COMPILER_SV2017_PARSER_H_
#define SVS_COMPILER_SV2017_PARSER_H_

#include <string>

#include "ast_module_declaration.h"
#include "parser_impl.h"

#define YY_DECL \
    yy::parser::symbol_type yylex(svs::sv2017::parser& parser)

namespace svs::sv2017 {

//
// Parser for SystemVerilog 2017.
//
class parser {
public:
    using result_t = ast::ast_t *;

    //
    // Constructor for the parser.
    //
    parser();

    //
    // Run the parser on the standard input stream.
    //
    result_t parse();

    //
    // Run the parser on the provided file.
    //
    result_t parse(const std::string& file_name);

private:
    //
    // Sets up the scanner for standard input.
    //
    void scan_begin();

    //
    // Sets up the scanner for a file input.
    //
    void scan_begin(const std::string& file_name);

    //
    // Tears down the scanner
    //
    void scan_end();

public:
    //
    // The parsing location
    //
    yy::location location;

private:
    //
    // The result of parsing.
    //
    result_t result;

    //
    // If true, the parser will generate parsing debug traces.
    //
    bool trace_parsing;

    //
    // If true, the parser will generate scanning debug traces.
    //
    bool trace_scanning;

public:
    friend yy::parser;
};

}

YY_DECL;

#endif // SVS_COMPILER_SV2017_PARSER_H_
