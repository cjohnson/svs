#include <cctype>
#include <memory>
#include <regex>

#include "Lexer.h"

#include "lexical_token/CommentLexicalToken.h"
#include "lexical_token/LexicalToken.h"
#include "lexical_token/OperatorLexicalToken.h"

std::vector<std::unique_ptr<svs::LexicalToken>> svs::Lexer::lex_file(
    const std::string& file_contents)
{
    std::vector<std::unique_ptr<svs::LexicalToken>> tokens;

    std::string::const_iterator search_start(file_contents.begin());
    std::string::const_iterator search_end(file_contents.end());

    std::string::const_iterator file_position_iterator(file_contents.begin());
    FilePosition file_position{ .line=0, .col=0 };

    while (search_start != search_end)
    {
        std::unique_ptr<svs::LexicalToken> lexical_token;

        std::smatch match;

        if (std::isspace(*search_start))
        {
            ++search_start;
            goto update_file_position;
        }

        lexical_token = svs::CommentLexicalToken::parse(
            file_position,
            search_start,
            search_end);
        if (lexical_token)
        {
            tokens.push_back(std::move(lexical_token));
            goto update_file_position;
        }

        lexical_token = svs::OperatorLexicalToken::parse(
            file_position,
            search_start,
            search_end);
        if (lexical_token)
        {
            tokens.push_back(std::move(lexical_token));
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

    return tokens;
}

