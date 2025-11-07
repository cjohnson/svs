#include <sstream>

#include "ast_module_declaration.h"

using namespace svs::sv2017;

ast::module_declaration_t::module_declaration_t(
        const std::string& identifier)
    : _identifier(identifier) { }

std::string ast::module_declaration_t::to_json(size_t indent_level) {
    std::stringstream ss;

    with_indent(ss, indent_level++) << "{\n";
    with_indent(ss, indent_level) << "\"declaration_type\": \"module\",\n";
    with_indent(ss, indent_level) << "\"identifier\": \"" << _identifier << "\"\n";
    with_indent(ss, --indent_level) << "}";

    return ss.str();
}

