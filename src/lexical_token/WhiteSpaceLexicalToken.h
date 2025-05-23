#ifndef SVS_WHITE_SPACE_LEXICAL_TOKEN_H_
#define SVS_WHITE_SPACE_LEXICAL_TOKEN_H_

#include <regex>

#include "LexicalToken.h"

namespace svs
{

class WhiteSpaceLexicalToken : public svs::LexicalToken
{
public:
    WhiteSpaceLexicalToken(
        const FilePosition& __file_position,
        const std::string& __raw_token);

    const std::string to_string() const override;

    static const std::regex regex;
};

}

#endif // SVS_WHITE_SPACE_LEXICAL_TOKEN_H_
