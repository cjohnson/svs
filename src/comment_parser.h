#ifndef SVS_COMMENT_PARSER_H_
#define SVS_COMMENT_PARSER_H_

#include "parser.h"

namespace svs
{

/**
 * Class that attempts to parse a SystemVerilog comment from a string.
 */
class CommentParser : public Parser<std::string>
{
public:
    /**
     * Attempt to parse a SystemVerilog comment from the string.
     *
     * Keyword arguments:
     * begin: The begin iterator of the string pointing to the position
     *        to begin to attempt to parse from.
     * end: The end iterator of the string to attempt to parse from.
     */
    svs::ParseResult<std::string> parse(
        const std::string::const_iterator& begin,
        const std::string::const_iterator& end) const;
};

}

#endif // SVS_COMMENT_PARSER_H_
