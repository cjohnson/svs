#include <sstream>

#include "CommentLexicalToken.h"

svs::CommentLexicalToken::CommentLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token,
    const svs::CommentLexicalToken::Type& __comment_type)
    : svs::LexicalToken(
        svs::LexicalToken::Type::Comment,
        __file_position,
        __raw_token),
      _comment_type(__comment_type)
{}

const std::string svs::CommentLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "CommentLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  Syntax=\"" << raw_token() << "\",\n";

    switch (_comment_type)
    {
    case OneLine:
        ss << "  CommentType=OneLine\n";
        break;
    case Block:
        ss << "  CommentType=Block\n";
        break;
    }

    ss << "}";

    return ss.str();
}

