#ifndef SVS_LEXICAL_TOKEN_H_
#define SVS_LEXICAL_TOKEN_H_

#include <string>

#include "../FilePosition.h"

namespace svs {

class LexicalToken
{
public:
    enum Type
    {
        WhiteSpace,
        Comment,
        Operator,
    };

public:
    LexicalToken(
        const Type& __type,
        const svs::FilePosition& __file_position,
        const std::string& __raw_token);

    virtual ~LexicalToken() = default;

    const bool is_ignored() const;

    const Type& type() const;

    const svs::FilePosition& file_position() const;

    const std::string& raw_token() const;

    const virtual std::string to_string() const = 0;

private:
    Type _type;
    svs::FilePosition _file_position;
    std::string _raw_token;
};

}

#endif // SVS_LEXICAL_TOKEN_H_
