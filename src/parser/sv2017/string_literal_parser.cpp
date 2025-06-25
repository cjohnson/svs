#include "string_literal_parser.h"

svs::ParseResult<std::string> svs::StringLiteralParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    const svs::CharacterParser double_quote_parser{'"'};
    const svs::CharacterParser backslash_parser{'\\'};

    const svs::ParseResult<char> opening_double_quote_result =
        double_quote_parser.parse(begin, end);
    if (!opening_double_quote_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    std::stringstream ss;
    std::string::const_iterator it = opening_double_quote_result.next();
    while (it != end)
    {
        svs::ParseResult<char> ending_double_quote_result =
            double_quote_parser.parse(it, end);
        if (ending_double_quote_result.succeeded())
        {
            return svs::ParseResult<std::string>::succeed(ss.str(), ending_double_quote_result.next());
        }

        svs::ParseResult<char> backslash_result =
            backslash_parser.parse(it, end);
        if (!backslash_result.succeeded())
        {
            ss << *it;
            ++it;

            continue;
        }

        ++it;
        if (it == end)
        {
            return svs::ParseResult<std::string>::fail();
        }

        switch (*it)
        {
        case '\n':
            ++it;
            break;
        default:
            ss << '\\';
            ss << *it;
            ++it;
            break;
        }
    }
    return svs::ParseResult<std::string>::fail();
}
