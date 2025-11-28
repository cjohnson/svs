// Copyright (c) 2025 Collin Johnson

#include "source_text.h"

#include <string>
#include <sstream>

std::string svs::sv2017::ast::SourceText::to_json(size_t indent_level) {
    std::stringstream ss;

    with_indent(ss, indent_level++) << "{\n";
    with_indent(ss, indent_level) << "\"version\": \"2017\",\n";
    with_indent(ss, indent_level++) << "\"declarations\": [\n";
    for (const auto& description : descriptions_)
        ss << description->to_json(indent_level) << ",\n";
    with_indent(ss, --indent_level) << "]\n";
    with_indent(ss, --indent_level) << "}";

    return ss.str();
}

