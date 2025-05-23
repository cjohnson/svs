#ifndef SVS_LEXER_H_
#define SVS_LEXER_H_

#include <string>
#include <vector>

#include "lexical_token/LexicalToken.h"

namespace svs
{

class Lexer
{
public:
    bool lex_file(
        const std::string& file_contents,
        std::vector<LexicalToken *>& tokens);
};

}

#endif // SVS_LEXER_H_
