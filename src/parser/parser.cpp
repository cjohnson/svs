#include "parser.h"

svs::CharacterParser::CharacterParser(const char c)
    : _match_set(std::unordered_set<char>{ c })
{}

svs::CharacterParser::CharacterParser(const std::unordered_set<char>& match_set)
    : _match_set(match_set)
{}

svs::ParseResult<char> svs::CharacterParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    if (begin == end || _match_set.find(*begin) == _match_set.end())
    {
        return svs::ParseResult<char>::fail();
    }
    return svs::ParseResult<char>::succeed(*begin, begin + 1);
}

svs::StringParser::StringParser(const std::string& match_string)
    : _match_string(match_string)
{}

svs::ParseResult<std::string> svs::StringParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    if (_match_string.empty())
    {
        return svs::ParseResult<std::string>::succeed(_match_string, begin);
    }

    std::string::const_iterator source_it = begin;
    std::string::const_iterator match_it = _match_string.begin();

    svs::ParseResult<char> result = svs::CharacterParser(*match_it).parse(source_it, end);
    while (result.succeeded())
    {
        ++source_it;
        ++match_it;

        if (match_it == _match_string.end())
        {
            return svs::ParseResult<std::string>::succeed(_match_string, source_it);
        }

        result = svs::CharacterParser(*match_it).parse(source_it, end);
    }
    return svs::ParseResult<std::string>::fail();
}

svs::ParseResult<char> svs::AlphabeticCharacterParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    if (begin == end || !std::isalpha(*begin))
    {
        return svs::ParseResult<char>::fail();
    }
    return svs::ParseResult<char>::succeed(*begin, begin + 1);
}

svs::ParseResult<char> svs::AlphanumericCharacterParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    if (begin == end || !std::isalnum(*begin))
    {
        return svs::ParseResult<char>::fail();
    }
    return svs::ParseResult<char>::succeed(*begin, begin + 1);
}
