#ifndef SVS_COMMENT_LEXICAL_TOKEN_H_
#define SVS_COMMENT_LEXICAL_TOKEN_H_

#include <regex>

#include "LexicalToken.h"

namespace svs
{

class CommentLexicalToken : public svs::LexicalToken
{
public:
    enum Type
    {
        OneLine,
        Block,
    };

    CommentLexicalToken(
        const svs::FilePosition& __file_position,
        const Type& __comment_type);

    const Type& comment_type();

    const std::string to_string() const override;

    static std::unique_ptr<CommentLexicalToken> parse(
        svs::FilePosition& file_position,
        std::string::const_iterator& begin,
        const std::string::const_iterator end);

private:
    Type _comment_type;
};

}

#endif // SVS_COMMENT_LEXICAL_TOKEN_H_
