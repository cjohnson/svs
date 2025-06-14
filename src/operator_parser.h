#ifndef SVS_OPERATOR_PARSER_H_
#define SVS_OPERATOR_PARSER_H_

#include "parse_result.h"
#include "parser.h"

namespace svs
{

/**
 * An assignment operator.
 */
enum AssignmentOperator
{
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
     * The modulo assignment operator.
     *
     * Syntax: '%='
     */
    ModuloAssignment,

    /**
     * The bitwise and assignment operator.
     *
     * Syntax: '&='
     */
    BitwiseAndAssignment,

    /**
     * The bitwise or assignment operator.
     *
     * Syntax: '|='
     */
    BitwiseOrAssignment,

    /**
     * The bitwise xor assignment operator.
     *
     * Syntax: '^='
     */
    BitwiseXorAssignment,

    /**
     * The left logical shift assignment operator.
     *
     * Syntax: '<<='
     */
    LogicalLeftShiftAssignment,

    /**
     * The right logical shift assignment operator.
     *
     * Syntax: '>>='
     */
    LogicalRightShiftAssignment,

    /**
     * The left arithmetic shift assignment operator.
     *
     * Syntax: '<<<='
     */
    ArithmeticLeftShiftAssignment,

    /**
     * The right arithmetic shift assignment operator.
     *
     * Syntax: '>>>='
     */
    ArithmeticRightShiftAssignment,
};

/**
 * An assignment operator parser.
 */
class AssignmentOperatorParser : public Parser<svs::AssignmentOperator>
{
public:
    /**
     * Attempt to parse an assignment operator.
     */
    svs::ParseResult<svs::AssignmentOperator> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * A unary operator.
 */
enum UnaryOperator
{
    /**
     * The positive sign unary operator.
     *
     * Syntax: '+'
     */
    PositiveSignUnaryOperator,

    /**
     * The negative sign unary operator.
     *
     * Syntax: '-'
     */
    NegativeSignUnaryOperator,

    /**
     * The logical negation unary operator.
     *
     * Syntax: '!'
     */
    LogicalNegationUnaryOperator,

    /**
     * The bitwise negation unary operator.
     *
     * Syntax: '~'
     */
    BitwiseNegationUnaryOperator,

    /**
     * The bitwise and unary operator.
     *
     * Syntax: '&'
     */
    BitwiseAndUnaryOperator,

    /**
     * The bitwise nand unary operator.
     *
     * Syntax: '~&'
     */
    BitwiseNandUnaryOperator,

    /**
     * The bitwise or unary operator.
     *
     * Syntax: '|'
     */
    BitwiseOrUnaryOperator,

    /**
     * The bitwise nor unary operator.
     *
     * Syntax: '~|'
     */
    BitwiseNorUnaryOperator,

    /**
     * The bitwise xor unary operator.
     *
     * Syntax: '^'
     */
    BitwiseXorUnaryOperator,

    /**
     * The bitwise xnor unary operator.
     *
     * Syntax: '~^' OR '^~'
     */
    BitwiseXnorUnaryOperator,
};

/**
 * A unary operator parser.
 */
class UnaryOperatorParser : public Parser<svs::UnaryOperator>
{
public:
    /**
     * Attempt to parse a unary operator.
     */
    svs::ParseResult<svs::UnaryOperator> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * A binary operator.
 */
enum BinaryOperator
{
    /**
     * The addition operator.
     *
     * Syntax: '+'
     */
    AdditionBinaryOperator,

    /**
     * The subtraction operator.
     *
     * Syntax: '-'
     */
    SubtractionBinaryOperator,

    /**
     * The multiplication operator.
     *
     * Syntax: '*'
     */
    MultiplicationBinaryOperator,

    /**
     * The division operator.
     *
     * Syntax: '/'
     */
    DivisionBinaryOperator,

    /**
     * The modulo operator.
     *
     * Syntax: '%'
     */
    ModuloBinaryOperator,

    /**
     * The exponentiation operator.
     *
     * Syntax: '**'
     */
    ExponentiationBinaryOperator,

    // Relational operators

    /**
     * The less than operator.
     *
     * Syntax: '<'
     */
    LessThanBinaryOperator,

    /**
     * The greater than operator.
     *
     * Syntax: '>'
     */
    GreaterThanBinaryOperator,

    /**
     * The less than or equal to operator.
     *
     * Syntax: '<='
     */
    LessThanOrEqualToBinaryOperator,

    /**
     * The greater than or equal to operator.
     *
     * Syntax: '>='
     */
    GreaterThanOrEqualToBinaryOperator,

    // Equality operators

    /**
     * The case equality operator.
     *
     * Syntax: '==='
     */
    CaseEqualityBinaryOperator,

    /**
     * The case inequality operator.
     *
     * Syntax: '!=='
     */
    CaseInequalityBinaryOperator,

    /**
     * The logical equality operator.
     *
     * Syntax: '=='
     */
    LogicalEqualityBinaryOperator,

    /**
     * The logical inequality operator.
     *
     * Syntax: '!='
     */
    LogicalInequalityBinaryOperator,

    // Wildcard equality operators

    /**
     * The wildcard equality operator.
     *
     * Syntax: '==?'
     */
    WildcardEqualityBinaryOperator,

    /**
     * The wildcard inequality operator.
     *
     * Syntax: '!=?'
     */
    WildcardInequalityBinaryOperator,

    // Logical operators

    /**
     * The logical and operator.
     *
     * Syntax: '&&'
     */
    LogicalAndBinaryOperator,

    /**
     * The logical or operator.
     *
     * Syntax: '||'
     */
    LogicalOrBinaryOperator,

    /**
     * The logical implication operator.
     *
     * Syntax: '->'
     */
    LogicalImplicationBinaryOperator,

    /**
     * The logical equivalence operator.
     *
     * Syntax: '<->'
     */
    LogicalEquivalenceBinaryOperator,

    /**
     * The logical negation operator.
     *
     * Syntax: '!'
     */
    LogicalNegationBinaryOperator,

    // Bitwise operators

    /**
     * The bitwise and operator.
     *
     * Syntax: '&'
     */
    BitwiseAndBinaryOperator,

    /**
     * The bitwise or operator.
     *
     * Syntax: '|'
     */
    BitwiseOrBinaryOperator,

    /**
     * The bitwise xor operator.
     *
     * Syntax: '^'
     */
    BitwiseXorBinaryOperator,

    /**
     * The bitwise xnor operator.
     *
     * Syntax: '^~' OR '~^'
     */
    BitwiseXnorBinaryOperator,

    /**
     * The bitwise negation operator.
     *
     * Syntax: '~'
     */
    BitwiseNegationBinaryOperator,

    // Shift operators

    /**
     * The logical left shift operator.
     *
     * Syntax: '<<'
     */
    LogicalLeftShiftBinaryOperator,

    /**
     * The logical right shift operator.
     *
     * Syntax: '>>'
     */
    LogicalRightShiftBinaryOperator,

    /**
     * The arithmetic left shift operator.
     *
     * Syntax: '<<<'
     */
    ArithmeticLeftShiftBinaryOperator,

    /**
     * The arithmetic right shift operator.
     *
     * Syntax: '>>>'
     */
    ArithmeticRightShiftBinaryOperator,
};

class BinaryOperatorParser : public Parser<svs::BinaryOperator>
{
public:
    /**
     * Attempt to parse an operator.
     */
    svs::ParseResult<svs::BinaryOperator> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * An increment or decrement operator.
 */
enum IncrementOrDecrementOperator
{
    /**
     * The increment operator.
     *
     * Syntax: '++'
     */
    IncrementOperator,

    /**
     * The decrement operator.
     *
     * Syntax: '--'
     */
    DecrementOperator,
};

/**
 * An increment or decrement operator parser.
 */
class IncrementOrDecrementOperatorParser : public Parser<svs::IncrementOrDecrementOperator>
{
public:
    /**
     * Attempt to parse an operator.
     */
    svs::ParseResult<svs::IncrementOrDecrementOperator> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

}

#endif // SVS_OPERATOR_PARSER_H_
