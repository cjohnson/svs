#ifndef SVS_PARSER_H_
#define SVS_PARSER_H_

#include <memory>
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
};

/**
 * Class that attempts to parse using the provided parser from a string.
 * If the parser fails, this parser still succeeds and returns the begin iterator.
 */
template<typename T>
class OptionalParser : public svs::Parser<T>
{
public:
    /**
     * Creates an optional parser.
     *
     * Keyword arguments:
     * parser: The parser that this parser parses with.
     */
    OptionalParser(const svs::Parser<T>& parser)
        : _parser(parser)
    { }

    /**
     * Attempt to parse using the provided parser.
     * If the parser fails, this parser still succeeds and returns the begin iterator.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<T> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override
    {
        svs::ParseResult<T> result = _parser.parse(begin, end);
        if (!result.succeeded())
        {
            return svs::ParseResult<T>::succeed(T(), begin);
        }
        return svs::ParseResult<T>::succeed(result.value(), result.next());
    }

private:
    /**
     * The set of parsers that this parser can parse with.
     */
    const svs::Parser<T>& _parser;
};

/**
 * Class that consumes characters until the provided parser succeeds from a string.
 */
template<typename T>
class UntilSuccessParser : public svs::Parser<std::string>
{
public:
    /**
     * Creates a take-until parser.
     *
     * Keyword arguments:
     * parser: The internal parser for determining the end criteria.
     */
    UntilSuccessParser(const svs::Parser<T>& parser)
        : _parser(parser), _consume_final_match(false)
    { }

    /**
     * Creates a take-until parser.
     *
     * Keyword arguments:
     * parser: The internal parser for determining the end criteria.
     */
    UntilSuccessParser(
        const svs::Parser<T>& parser,
        const bool consume_final_match)
        :   _parser(parser),
            _consume_final_match(consume_final_match)
    { }

    /**
     * Consumes characters until the provided parser succeeds
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override
    {
        std::stringstream ss;
        std::string::const_iterator it = begin;

        svs::ParseResult<T> result = _parser.parse(it, end);
        while (!result.succeeded())
        {
            if (it == end)
            {
                return svs::ParseResult<std::string>::fail();
            }
            ss << *it;
            ++it;

            result = _parser.parse(it, end);
        }

        if (_consume_final_match)
        {
            it = result.next();
        }

        return svs::ParseResult<std::string>::succeed(ss.str(), it);
    }

private:
    const svs::Parser<T>& _parser;
    const bool _consume_final_match;
};

/**
 * Class that attempts to parse using any of the provided parsers from a string.
 */
template<typename T>
class AnyParser : public svs::Parser<T>
{
public:
    /**
     * Creates an any-match parser.
     *
     * Keyword arguments:
     * parser_set: The set of parsers that this parser can parse with.
     */
    AnyParser(const std::vector<std::shared_ptr<svs::Parser<T>>>& parser_set)
        : _parser_set(parser_set)
    { }

    /**
     * Attempt to parse using any of the parsers from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<T> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override
    {
        for (const auto& parser : _parser_set)
        {
            svs::ParseResult<T> result = parser->parse(begin, end);
            if (result.succeeded())
            {
                return svs::ParseResult<T>::succeed(
                    result.value(),
                    result.next());
            }
        }

        return svs::ParseResult<T>::fail();
    }

private:
    /**
     * The set of parsers that this parser can parse with.
     */
    const std::vector<std::shared_ptr<svs::Parser<T>>> _parser_set;
};

/**
 * Class that attempts to parse one or more structures the provided parser from a string.
 */
template<typename T>
class SomeParser : public svs::Parser<std::vector<T>>
{
public:
    /**
     * Creates an some-match parser.
     *
     * Keyword arguments:
     * parser: The unit parser this parser parses with.
     */
    SomeParser(const svs::Parser<T>& parser)
        : _parser(parser)
    { }

    /**
     * Attempt to parse using any of the parsers from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::vector<T>> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override
    {
        svs::ParseResult<T> result = _parser.parse(begin, end);
        if (!result.succeeded())
        {
            return svs::ParseResult<std::vector<T>>::fail();
        }

        std::vector<T> results;
        std::string::const_iterator it = result.next();
        while (result.succeeded())
        {
            it = result.next();
            results.push_back(result.value());
            result = _parser.parse(it, end);
        }
        return svs::ParseResult<std::vector<T>>::succeed(results, it);
    }

private:
    /**
     * The unit parser this parser parses with.
     */
    const svs::Parser<T>& _parser;
};

/**
 * Class that attempts to parse one or more structures the provided parser from a string.
 */
template<>
class SomeParser<char> : public svs::Parser<std::string>
{
public:
    /**
     * Creates an some-match parser.
     *
     * Keyword arguments:
     * parser: The unit parser this parser parses with.
     */
    SomeParser(const std::shared_ptr<svs::Parser<char>>& parser)
        : _parser(parser)
    { }

    /**
     * Attempt to parse using any of the parsers from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override
    {
        svs::ParseResult<char> result = _parser->parse(begin, end);
        if (!result.succeeded())
        {
            return svs::ParseResult<std::string>::fail();
        }

        std::stringstream results;
        std::string::const_iterator it = result.next();
        while (result.succeeded())
        {
            it = result.next();
            results << result.value();
            result = _parser->parse(it, end);
        }
        return svs::ParseResult<std::string>::succeed(results.str(), it);
    }

private:
    /**
     * The unit parser this parser parses with.
     */
    const std::shared_ptr<svs::Parser<char>> _parser;
};

/**
 * Class that attempts to parse a single character from a string.
 */
class CharacterParser : public svs::Parser<char>
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
 * Class that attempts to parse a single alphabetic character from a string.
 */
class AlphabeticCharacterParser : public svs::Parser<char>
{
public:
    /**
     * Attempt to parse an alphabetic character from the string.
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

/**
 * Class that attempts to parse a single alphanumeric character from a string.
 */
class AlphanumericCharacterParser : public svs::Parser<char>
{
public:
    /**
     * Attempt to parse an alphanumeric character from the string.
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
