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
 * The type of operator.
 */
enum OperatorType
{
    // Assignment operators

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

    // Increment and decrement operators

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

    // Arithmetic operators

    /**
     * The addition operator.
     *
     * Syntax: '+'
     */
    Addition,

    /**
     * The subtraction operator.
     *
     * Syntax: '-'
     */
    Subtraction,

    /**
     * The multiplication operator.
     *
     * Syntax: '*'
     */
    Multiplication,

    /**
     * The division operator.
     *
     * Syntax: '/'
     */
    Division,

    /**
     * The modulo operator.
     *
     * Syntax: '%'
     */
    Modulo,

    /**
     * The exponentiation operator.
     *
     * Syntax: '**'
     */
    Exponentiation,

    // Relational operators

    /**
     * The less than operator.
     *
     * Syntax: '<'
     */
    LessThan,

    /**
     * The greater than operator.
     *
     * Syntax: '>'
     */
    GreaterThan,

    /**
     * The less than or equal to operator.
     *
     * Syntax: '<='
     */
    LessThanOrEqualTo,

    /**
     * The greater than or equal to operator.
     *
     * Syntax: '>='
     */
    GreaterThanOrEqualTo,

    // Equality operators

    /**
     * The case equality operator.
     *
     * Syntax: '==='
     */
    CaseEquality,

    /**
     * The case inequality operator.
     *
     * Syntax: '!=='
     */
    CaseInequality,

    /**
     * The logical equality operator.
     *
     * Syntax: '=='
     */
    LogicalEquality,

    /**
     * The logical inequality operator.
     *
     * Syntax: '!='
     */
    LogicalInequality,

    // Wildcard equality operators

    /**
     * The wildcard equality operator.
     *
     * Syntax: '==?'
     */
    WildcardEquality,

    /**
     * The wildcard inequality operator.
     *
     * Syntax: '!=?'
     */
    WildcardInequality,

    // Logical operators

    /**
     * The logical and operator.
     *
     * Syntax: '&&'
     */
    LogicalAnd,

    /**
     * The logical or operator.
     *
     * Syntax: '||'
     */
    LogicalOr,

    /**
     * The logical implication operator.
     *
     * Syntax: '->'
     */
    LogicalImplication,

    /**
     * The logical equivalence operator.
     *
     * Syntax: '<->'
     */
    LogicalEquivalence,

    /**
     * The logical negation operator.
     *
     * Syntax: '!'
     */
    LogicalNegation,

    // Bitwise operators

    /**
     * The bitwise and operator.
     *
     * Syntax: '&'
     */
    BitwiseAnd,

    /**
     * The bitwise or operator.
     *
     * Syntax: '|'
     */
    BitwiseOr,

    /**
     * The bitwise xor operator.
     *
     * Syntax: '^'
     */
    BitwiseXor,

    /**
     * The bitwise xnor operator.
     *
     * Syntax: '^~' OR '~^'
     */
    BitwiseXnor,

    /**
     * The bitwise negation operator.
     *
     * Syntax: '~'
     */
    BitwiseNegation,

    // Shift operators

    /**
     * The logical left shift operator.
     *
     * Syntax: '<<'
     */
    LogicalLeftShift,

    /**
     * The logical right shift operator.
     *
     * Syntax: '>>'
     */
    LogicalRightShift,

    /**
     * The arithmetic left shift operator.
     *
     * Syntax: '<<<'
     */
    ArithmeticLeftShift,

    /**
     * The arithmetic right shift operator.
     *
     * Syntax: '>>>'
     */
    ArithmeticRightShift,

    // Conditional operator

    /**
     * The conditional predicate operator.
     *
     * Syntax: '?'
     */
    ConditionalPredicateOperator,

    /**
     * The conditional expression delimiter operator.
     *
     * Syntax: ':'
     */
    ConditionalExpressionDelimiter,

    // TODO concatenation operator?

    // TODO replication operator?

    // TODO String concatenation?

    // Set membership operator

    /**
     * The set membership operator.
     *
     * Syntax: 'inside'
     */
    SetMembershipOperator,

    // TODO Streaming operators?
};

class OperatorParser : public Parser
{
public:
    /**
     * Attempt to parse an operator.
     */
    svs::ParseResult<OperatorType> parse(
        const std::string::const_iterator _begin,
        const std::string::const_iterator _end);
};

}

