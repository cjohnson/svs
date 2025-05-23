#include <sstream>

#include "WhiteSpaceLexicalToken.h"

svs::WhiteSpaceLexicalToken::WhiteSpaceLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : svs::LexicalToken(
        svs::LexicalToken::Type::WhiteSpace,
        __file_position,
        __raw_token)
{}

const std::string svs::WhiteSpaceLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "WhiteSpaceLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\"\n";
    ss << "}";

    return ss.str();
}

