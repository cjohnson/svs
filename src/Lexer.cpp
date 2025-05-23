#include <regex>

#include "Lexer.h"

#include "lexical_token/WhiteSpaceLexicalToken.h"
#include "lexical_token/CommentLexicalToken.h"
#include "lexical_token/OperatorLexicalToken.h"

bool svs::Lexer::lex_file(
    const std::string& file_contents,
    std::vector<svs::LexicalToken *>& tokens)
{
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
                svs::WhiteSpaceLexicalToken::regex,
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
                svs::CommentLexicalToken::one_line_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalToken::Type::OneLine);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                svs::CommentLexicalToken::block_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::CommentLexicalToken(
                file_position,
                match.str(),
                svs::CommentLexicalToken::Type::Block);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                svs::OperatorLexicalToken::regex(),
                std::regex_constants::match_continuous))
        {
            auto token = new svs::OperatorLexicalToken(
                file_position,
                match.str());
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

