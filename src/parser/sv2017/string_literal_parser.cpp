#include "string_literal_parser.h"

svs::ParseResult<std::string> svs::StringLiteralParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    const svs::CharacterParser double_quote_parser('\"');

    svs::ParseResult<char> opening_double_quote_result =
        double_quote_parser.parse(begin, end);
    if (!opening_double_quote_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    return svs::UntilSuccessParser<char>
    {
        double_quote_parser,
        true,
    }.parse(opening_double_quote_result.next(), end);
}
