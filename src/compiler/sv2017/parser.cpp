#include "parser.h"

using namespace svs::sv2017;

parser::parser() : trace_parsing(false), trace_scanning(false) { }

parser::result_t parser::parse() {
    location.initialize();

    scan_begin();

    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    if (parser.parse() != 0)
        result = nullptr;

    scan_end();

    return result;
}

parser::result_t parser::parse(const std::string& file_name) {
    location.initialize(&file_name);

    scan_begin(file_name);

    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    if (parser.parse() != 0)
        result = nullptr;

    scan_end();

    return result;
}

