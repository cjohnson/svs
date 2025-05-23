#ifndef SVS_OPERATOR_LEXICAL_TOKEN_H_
#define SVS_OPERATOR_LEXICAL_TOKEN_H_

#include <regex>

#include "LexicalToken.h"

namespace svs
{

class OperatorLexicalToken : public svs::LexicalToken
{
public:
    enum Type
    {
        // Assignment Operators
        Equals,
        PlusEquals,
        MinusEquals,
        TimesEquals,
        DivideEquals,
        ModuloEquals,
        BitwiseAndEquals,
        BitwiseOrEquals,
        BitwiseExclusiveOrEquals,
        LogicalLeftShiftEquals,
        LogicalRightShiftEquals,
        ArithmeticLeftShiftEquals,
        ArithmeticRightShiftEquals,

        // Increment and Decrement Operators
        Increment,
        Decrement,
    };

    OperatorLexicalToken(
        const svs::FilePosition& __file_position,
        const std::string& __raw_token);

    const std::string to_string() const override;

    static const std::regex regex();

private:
    OperatorLexicalToken::Type _operator_type;
};

}

#endif // SVS_OPERATOR_LEXICAL_TOKEN_H_
