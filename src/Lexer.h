#ifndef SVS_LEXER_H_
#define SVS_LEXER_H_

#include <memory>
#include <string>
#include <vector>

#include "lexical_token/LexicalToken.h"

namespace svs
{

class Lexer
{
public:
    std::vector<std::unique_ptr<LexicalToken>> lex_file(
        const std::string& file_contents);
};

}

#endif // SVS_LEXER_H_
