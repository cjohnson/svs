#include <memory>
#include <sstream>

#include "CommentLexicalToken.h"

svs::CommentLexicalToken::CommentLexicalToken(
    const svs::FilePosition& __file_position,
    const svs::CommentLexicalToken::Type& __comment_type)
    : svs::LexicalToken(
        svs::LexicalToken::Type::Comment,
        __file_position),
      _comment_type(__comment_type)
{}

const auto one_line_regex = std::regex("\\/\\/.*$", std::regex_constants::multiline);
const auto block_regex = std::regex("\\/\\*(.|\n)*\\*\\/");

std::unique_ptr<svs::CommentLexicalToken> svs::CommentLexicalToken::parse(
    svs::FilePosition& file_position,
    std::string::const_iterator& begin,
    const std::string::const_iterator end)
{
    std::smatch match;

    if (std::regex_search(
            begin,
            end,
            match,
            one_line_regex,
            std::regex_constants::match_continuous))
    {
        begin = match.suffix().first;
        return std::unique_ptr<svs::CommentLexicalToken>(
            new svs::CommentLexicalToken(
                file_position,
                svs::CommentLexicalToken::Type::OneLine));
    }

    if (std::regex_search(
            begin,
            end,
            match,
            block_regex,
            std::regex_constants::match_continuous))
    {
        begin = match.suffix().first;
        return std::unique_ptr<svs::CommentLexicalToken>(
            new svs::CommentLexicalToken(
                file_position,
                svs::CommentLexicalToken::Type::Block));
    }

    return nullptr;
}

const std::string svs::CommentLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "CommentLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";

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

