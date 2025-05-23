#ifndef SVS_ASSIGNMENT_OPERATOR_LEXICAL_TOKEN_H_
#define SVS_ASSIGNMENT_OPERATOR_LEXICAL_TOKEN_H_

#include <regex>

#include "LexicalToken.h"

namespace svs
{

class AssignmentOperatorLexicalToken : public svs::LexicalToken
{
public:
    enum Type
    {
        Simple,
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
    };

    AssignmentOperatorLexicalToken(
        const svs::FilePosition& __file_position,
        const std::string& __raw_token);

    const std::string to_string() const override;

    static const std::regex regex;

private:
    Type _assignment_operator_type;
};

}

#endif // SVS_ASSIGNMENT_OPERATOR_LEXICAL_TOKEN_H_
