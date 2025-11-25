#include <sstream>

#include "ast_module_declaration.h"

using namespace svs::sv2017;

ast::module_header_t::module_header_t(const std::string& identifier)
    : _identifier(identifier) { }

ast::module_ansi_header_t::module_ansi_header_t(const std::string& identifier)
    : ast::module_header_t(identifier) { }

std::string ast::module_ansi_header_t::to_json(size_t indent_level) {
    std::stringstream ss;

    ss << "{\n";
    with_indent(ss, indent_level) << "\"identifier\": \""
        << _identifier << "\"\n";
    with_indent(ss, --indent_level) << "}";

    return ss.str();
}

ast::module_declaration_t::module_declaration_t(
        std::unique_ptr<module_header_t> header)
    : _header(std::move(header)) { }

std::string ast::module_declaration_t::to_json(size_t indent_level) {
    std::stringstream ss;

    with_indent(ss, indent_level++) << "{\n";
    with_indent(ss, indent_level) << "\"declaration_type\": \"module\",\n";
    with_indent(ss, indent_level) << "\"header\": "
        << _header->to_json(indent_level + 1) << "\n";
    with_indent(ss, --indent_level) << "}";

    return ss.str();
}

