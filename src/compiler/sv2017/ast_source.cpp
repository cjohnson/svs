#include <sstream>

#include "ast_source.h"

using namespace svs::sv2017;

std::string ast::source_t::to_json(size_t indent_level) {
    std::stringstream ss;

    with_indent(ss, indent_level++) << "{\n";
    with_indent(ss, indent_level) << "\"version\": \"2017\",\n";
    with_indent(ss, indent_level++) << "\"declarations\": [\n";
    for (const auto& description : _descriptions)
        ss << description->to_json(indent_level) << ",\n";
    with_indent(ss, --indent_level) << "]\n";
    with_indent(ss, --indent_level) << "}";

    return ss.str();
}

