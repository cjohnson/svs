#ifndef SVS_WHITE_SPACE_PARSER_H_
#define SVS_WHITE_SPACE_PARSER_H_

#include "../parser.h"

namespace svs
{

/**
 * Attempts to parse white space from strings.
 */
class WhiteSpaceParser : public Parser<char>
{
public:
    /**
     * Attempt to parse white space from a string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<char> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const override;
};

}

#endif // SVS_WHITE_SPACE_PARSER_H_
