#include "white_space_parser.h"

svs::ParseResult<char> svs::WhiteSpaceParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    if (begin == end)
    {
        return svs::ParseResult<char>::succeed((char)0, end);
    }

    if (std::isspace(*begin))
    {
        return svs::ParseResult<char>::succeed(*begin, begin + 1);
    }
    return svs::ParseResult<char>::fail();
}
