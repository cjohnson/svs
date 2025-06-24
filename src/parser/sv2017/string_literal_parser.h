#ifndef SVS_STRING_LITERAL_PARSER_H_
#define SVS_STRING_LITERAL_PARSER_H_

#include "../parser.h"

namespace svs
{

/**
 * Attempts to parse a string literal from strings.
 */
class StringLiteralParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse a string literal from a string.
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

#endif // SVS_STRING_LITERAL_PARSER_H_
