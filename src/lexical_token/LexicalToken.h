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
        Comment,
        Operator,
    };

public:
    LexicalToken(
        const Type& __type,
        const svs::FilePosition& __file_position);

    virtual ~LexicalToken() = default;

    const Type& type() const;

    const svs::FilePosition& file_position() const;

    const virtual std::string to_string() const = 0;

private:
    Type _type;
    svs::FilePosition _file_position;
};

}

#endif // SVS_LEXICAL_TOKEN_H_
