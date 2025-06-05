#ifndef SVS_OPERATOR_LEXICAL_TOKEN_H_
#define SVS_OPERATOR_LEXICAL_TOKEN_H_

#include <regex>
#include <sys/types.h>

#include "LexicalToken.h"

namespace svs
{

/**
 * The operator lexical token type.
 */
class OperatorLexicalToken : public svs::LexicalToken
{
public:
    /**
     * The type of operator.
     */
    enum Type
    {
        // Assignment Operators

        /**
         * The simple assignment operator.
         *
         * Syntax: '='
         */
        SimpleAssignment,

        /**
         * The addition assignment operator.
         *
         * Syntax: '+='
         */
        AdditionAssignment,

        /**
         * The subtraction assignment operator.
         *
         * Syntax: '-='
         */
        SubtractionAssignment,

        /**
         * The multiplication assignment operator.
         *
         * Syntax: '*='
         */
        MultiplicationAssignment,

        /**
         * The division assignment operator.
         *
         * Syntax: '/='
         */
        DivisionAssignment,

        /**
         * The modulo (integer remainder) assignment operator.
         *
         * Syntax: '%='
         */
        ModuloAssignment,

        /**
         * The bitwise AND assignment operator.
         *
         * Syntax: '&='
         */
        BitwiseAndAssignment,

        /**
         * The bitwise OR assignment operator.
         *
         * Syntax: '|='
         */
        BitwiseOrAssignment,

        /**
         * The bitwise exclusive or (XOR) assignment operator.
         *
         * Syntax: '^='
         */
        BitwiseExclusiveOrAssignment,

        /**
         * The logical left shift assignment operator.
         *
         * Syntax: '<<='
         */
        LogicalLeftShiftAssignment,

        /**
         * The logical right shift assignment operator.
         *
         * Syntax: '>>='
         */
        LogicalRightShiftAssignment,

        /**
         * The arithmetic left shift assignment operator.
         *
         * Syntax: '<<<='
         */
        ArithmeticLeftShiftAssignment,

        /**
         * The arithmetic right shift assignment operator.
         *
         * Syntax: '>>>='
         */
        ArithmeticRightShiftAssignment,

        // Increment and Decrement Operators

        /**
         * The increment operator.
         *
         * Syntax: '++'
         */
        Increment,

        /**
         * The decrement operator.
         *
         * Syntax: '--'
         */
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
