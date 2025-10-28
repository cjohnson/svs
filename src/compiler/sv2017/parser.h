#ifndef SVS_COMPILER_SV2017_PARSER_H_
#define SVS_COMPILER_SV2017_PARSER_H_

#include <memory>
#include <vector>
#include <string>

#include "parser_impl.h"

#define YY_DECL \
    yy::parser::symbol_type yylex(svs::sv2017::parser& parser)

namespace svs::sv2017 {

//
// Parser for SystemVerilog 2017.
//
class parser {
public:
    using result_t = std::shared_ptr<std::vector<std::string>>;

    //
    // Constructor for the parser.
    //
    parser();

    //
    // Run the parser on the standard input stream.
    // Returns 0 on success.
    //
    int parse();

    //
    // The result of parsing.
    //
    result_t result;

    //
    // The parsing location
    //
    yy::location location;

private:
    //
    // If true, the parser will generate parsing debug traces.
    //
    bool trace_parsing;

    //
    // If true, the parser will generate scanning debug traces.
    //
    bool trace_scanning;
};

}

YY_DECL;

#endif // SVS_COMPILER_SV2017_PARSER_H_
