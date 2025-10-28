#include "parser.h"

using namespace svs::sv2017;

parser::parser() : trace_parsing(false), trace_scanning(false) { }

int parser::parse() {
    yy::parser parser(*this);
    int result_code = parser.parse();
    return result_code;
}
