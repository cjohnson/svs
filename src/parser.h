#ifndef SVS_PARSER_H_
#define SVS_PARSER_H_

#include <sstream>
#include <unordered_set>
#include <vector>

#include "parse_result.h"

namespace svs
{

/**
 * Attempts to parse structures from strings.
 * Serves as the base class of the parsing framework.
 */
template<typename T>
class Parser
{
public:
    /**
     * Attempt to parse a structure from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    virtual svs::ParseResult<T> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const = 0;

    /**
     * Attempt to parse one or more structures from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::vector<T>> parse_some(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const
    {
        std::vector<T> vec;
        std::string::const_iterator it = begin;

        svs::ParseResult<T> result = parse(it, end);
        if (!result.succeeded())
        {
            return svs::ParseResult<std::vector<T>>::fail();
        }

        while (result.succeeded())
        {
            vec.push_back(result.value());
            it = result.next();

            result = parse(it, end);
        }
        return svs::ParseResult<std::vector<T>>::succeed(vec, it);
    }
};

/**
 * Attempts to parse characters from strings.
 * For repeated parsing, returns a string instead of a vector.
 */
template<>
class Parser<char>
{
public:
    /**
     * Attempt to parse a character from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    virtual svs::ParseResult<char> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const = 0;

    /**
     * Attempt to parse a substring from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse_some(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const
    {
        std::stringstream ss;
        std::string::const_iterator it = begin;

        svs::ParseResult<char> result = parse(it, end);
        if (!result.succeeded())
        {
            return svs::ParseResult<std::string>::fail();
        }

        while (result.succeeded())
        {
            ss << result.value();
            it = result.next();

            result = parse(it, end);
        }
        return svs::ParseResult<std::string>::succeed(ss.str(), it);
    }
};

/**
 * Class that attempts to parse a single character from a string.
 */
class CharacterParser : public Parser<char>
{
public:
    /**
     * Creates a single-match character parser.
     *
     * Keyword arguments:
     * match_char: The character this parser can match to.
     */
    CharacterParser(const char match_char);

    /**
     * Creates a character parser with a set of possible match options.
     *
     * Keyword arguments:
     * match_set: The set of characters this parser can match to.
     */
    CharacterParser(const std::unordered_set<char>& match_set);

    /**
     * Attempt to parse a character from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<char> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const;

private:
    /**
     * The set of characters that this parser can match to.
     */
    std::unordered_set<char> _match_set;
};

/**
 * Class that attempts to parse a string from a string.
 */
class StringParser : public Parser<std::string>
{
public:
    /**
     * Creates a single-match character parser.
     *
     * Keyword arguments:
     * match_string: The string this parser can match to.
     */
    StringParser(const std::string& match_string);

    /**
     * Attempt to parse a character from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const;

private:
    /**
     * The string this parser can match to.
     */
    std::string _match_string;
};

/**
 * Class that attempts to parse a single whitespace character from a string.
 */
class WhitespaceParser : public Parser<char>
{
public:
    /**
     * Attempt to parse a whitespace character from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<char> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const;
};

}

#endif // SVS_PARSER_H_
