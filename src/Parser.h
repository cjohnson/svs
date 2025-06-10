#include <cassert>
#include <sstream>
#include <string>
#include <unordered_set>

namespace svs
{

/**
 * The result of a parsing attempt.
 */
template<typename T>
class ParseResult
{
public:
    /**
     * Creates a successful parsing attempt result.
     *
     * Keyword arguments:
     * __value: The value created from the successful parsing attempt.
     * __next: The iterator pointing to the next part of the string that is now unconsumed.
     */
    static ParseResult<T> succeed(
        const T& __value,
        const std::string::const_iterator& __next)
    {
        svs::ParseResult<T> result;
        result._success = true;
        result._value = __value;
        result._next = __next;

        return result;
    }

    /**
     * Creates a failed parsing attempt result.
     */
    static ParseResult<T> fail()
    {
        svs::ParseResult<T> result;
        result._success = false;

        return result;
    }

    /**
     * Returns whether or not the parsing attempt succeeded:
     * the status of the parsing attempt result.
     */
    bool succeeded()
    {
        return _success;
    }

    /**
     * Returns the value created from the successful parsing attempt.
     */
    T& value()
    {
        assert(_success);
        return _value;
    }

    /**
     * Returns the iterator pointing to the next part of the string that is now unconsumed on
     * a successful parsing attempt.
     */
    std::string::const_iterator next()
    {
        assert(_success);
        return _next;
    }

private:
    /**
     * Constructs the result of a parsing attempt.
     */
    ParseResult<T>()
    {}

    bool _success;

    T _value;
    std::string::const_iterator _next;
};

/**
 * A parser.
 */
class Parser
{
public:
    /**
     * Parse a single character matching the provided match character.
     *
     * Keyword arguments:
     * _begin: The begin iterator to the string to attempt to parse from.
     * _end: The end iterator to the string to attempt to parse from.
     * _match_character: The character to match to.
     */
    svs::ParseResult<char> parse_character(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end,
        const char _match_character);

    /**
     * Parse a single character from a set of available match character.
     *
     * Keyword arguments:
     * _begin: The begin iterator to the string to attempt to parse from.
     * _end: The end iterator to the string to attempt to parse from.
     * _match_character_set: The set of characters to match to.
     */
    svs::ParseResult<char> parse_character(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end,
        const std::unordered_set<char>& _match_character_set);

    /**
     * Parse a string matching the provided match string.
     *
     * Keyword arguments:
     * _begin: The begin iterator to the string to attempt to parse from.
     * _end: The end iterator to the string to attempt to parse from.
     * _match_string: The string to match to.
     */
    svs::ParseResult<std::string> parse_string(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end,
        const std::string& _match_string);

    /**
     * Parse a contiguous list of whitespace characters.
     *
     * Keyword arguments:
     * _begin: The begin iterator to the string to attempt to parse from.
     * _end: The end iterator to the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse_whitespace(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);

    /**
     * Parse to the end of the line.
     *
     * Keyword arguments:
     * _begin: The begin iterator to the string to attempt to parse from.
     * _end: The end iterator to the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse_line(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
};

/**
 * A comment parser.
 */
class CommentParser : public Parser
{
public:
    /**
     * Attempt to parse a comment.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);

private:
    /**
     * Attempt to parse a one-line comment.
     */
    svs::ParseResult<std::string> parse_one_line_comment(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);

    /**
     * Attempt to parse a block comment.
     */
    svs::ParseResult<std::string> parse_block_comment(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
};

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
class AssignmentOperatorParser : public Parser
{
public:
    /**
     * Attempt to parse an assignment operator.
     */
    svs::ParseResult<svs::AssignmentOperator> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
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
class UnaryOperatorParser : public Parser
{
public:
    /**
     * Attempt to parse a unary operator.
     */
    svs::ParseResult<svs::UnaryOperator> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
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

class BinaryOperatorParser : public Parser
{
public:
    /**
     * Attempt to parse an operator.
     */
    svs::ParseResult<svs::BinaryOperator> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
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
class IncrementOrDecrementOperatorParser : public Parser
{
public:
    /**
     * Attempt to parse an operator.
     */
    svs::ParseResult<svs::IncrementOrDecrementOperator> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
};

}

