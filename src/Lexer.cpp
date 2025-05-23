#include <regex>

#include "Lexer.h"

#include "lexical_token/WhiteSpaceLexicalToken.h"
#include "lexical_token/CommentLexicalToken.h"
#include "lexical_token/AssignmentOperatorLexicalToken.h"

bool svs::Lexer::lex_file(
    const std::string& file_contents,
    std::vector<svs::LexicalToken *>& tokens)
{
    std::regex whitespace_regex("\\s+");
    std::regex one_line_comment_regex("\\/\\/.*$", std::regex_constants::multiline);
    std::regex block_comment_regex("\\/\\*(.|\n)*\\*\\/");
    std::regex assignment_operator_regex("(=)|(\\+=)|(-=)|(\\*=)|(/=)|(%=)|(&=)|(\\|=)|(\\^=)|(<<=)|(>>=)|(<<<=)|(>>>=)");

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
                svs::CommentLexicalToken::Type::OneLine);
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
                svs::CommentLexicalToken::Type::Block);
            tokens.push_back(token);

            search_start = match.suffix().first;

            goto update_file_position;
        }

        if (std::regex_search(
                search_start,
                search_end,
                match,
                assignment_operator_regex,
                std::regex_constants::match_continuous))
        {
            auto token = new svs::AssignmentOperatorLexicalToken(
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

