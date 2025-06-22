#ifndef SVS_IDENTIFIER_PARSER_H_
#define SVS_IDENTIFIER_PARSER_H_

#include "../parser.h"

namespace svs
{

/**
 * Class that attempts to parse an escaped identifier from a string.
 */
class EscapedIdentifierParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse an escaped identifier from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * Class that attempts to parse an identifier from a string.
 */
class IdentifierParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse an identifier from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * Class that attempts to parse a simple identifier from a string.
 */
class SimpleIdentifierParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse a simple identifier from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

/**
 * Class that attempts to parse a system task or function identifier from a string.
 */
class SystemTaskOrFunctionIdentifierParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse a system task or function identifier from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

}

#endif // SVS_IDENTIFIER_PARSER_H_

