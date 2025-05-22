#include <regex>

#include "Lexer.h"

const std::string svs::FilePosition::to_string() const
{
    std::stringstream ss;
    ss << "FilePosition{ ";
    ss << "Line=" << line << " ";
    ss << "Col=" << col << " ";
    ss << "}";

    return ss.str();
}

svs::LexicalToken::LexicalToken(
    const LexicalTokenType& __type,
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : _type(__type),
      _file_position(__file_position),
      _raw_token(__raw_token)
{}

const svs::LexicalTokenType& svs::LexicalToken::type() const
{
    return _type;
}

const svs::FilePosition& svs::LexicalToken::file_position() const
{
    return _file_position;
}

const std::string& svs::LexicalToken::raw_token() const
{
    return _raw_token;
}

svs::WhiteSpaceLexicalToken::WhiteSpaceLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token)
    : svs::LexicalToken(
        svs::LexicalTokenType::WhiteSpace,
        __file_position,
        __raw_token)
{}

svs::CommentLexicalToken::CommentLexicalToken(
    const svs::FilePosition& __file_position,
    const std::string& __raw_token,
    const svs::CommentLexicalTokenType& __comment_type)
    : svs::LexicalToken(
        svs::LexicalTokenType::Comment,
        __file_position,
        __raw_token),
      _comment_type(__comment_type)
{}

const std::string svs::WhiteSpaceLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "WhiteSpaceLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  RawContents=\"" << raw_token() << "\"\n";
    ss << "}";

    return ss.str();
}

const std::string svs::CommentLexicalToken::to_string() const
{
    std::stringstream ss;
    ss << "CommentLexicalToken{\n";
    ss << "  FilePosition=" << file_position().to_string() << ",\n";
    ss << "  RawContents=\"" << raw_token() << "\",\n";

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

bool svs::Lexer::lex_file(
    const std::string& file_contents,
    std::vector<svs::LexicalToken *>& tokens)
{
    std::regex whitespace_regex("\\s+");
    std::regex one_line_comment_regex("\\/\\/.*$", std::regex_constants::multiline);
    std::regex block_comment_regex("\\/\\*(.|\n)*\\*\\/");

    std::string::const_iterator search_start(file_contents.begin());
    std::string::const_iterator search_end(file_contents.end());

    std::string::const_iterator file_position_iterator(file_contents.begin());
    FilePosition file_position{ .line=0, .col=0 };

    while (search_start != search_end)
    {
        std::smatch match;

        if (std::regex_search(
                search_start,
                search_end,
                match,
                whitespace_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::WhiteSpaceLexicalToken(
                file_position,
                match.str());
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                one_line_comment_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalTokenType::OneLine);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                block_comment_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalTokenType::Block);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        ++search_start;

update_file_position:
        while (file_position_iterator < search_start)
        {
            if (*file_position_iterator == '\n')
            {
                ++file_position.line;
                file_position.col = 0;
            }
            else
            {
                ++file_position.col;
            }

            ++file_position_iterator;
        }
    }

    return true;
}

