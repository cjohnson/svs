#include <sstream>

#include "parse_result.h"
#include "parser.h"
#include "comment_parser.h"

static svs::ParseResult<std::string> parse_one_line_comment(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end)
{
    const svs::StringParser comment_begin_parser("//");
    const svs::CharacterParser new_line_parser('\n');

    std::string::const_iterator it = begin;

    svs::ParseResult<std::string> start_syntax_result = comment_begin_parser.parse(it, end);
    if (!start_syntax_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = start_syntax_result.next();

    std::stringstream ss;

    svs::ParseResult<char> new_line_result = new_line_parser.parse(it, end);
    while (!new_line_result.succeeded())
    {
        if (it == end)
        {
            return svs::ParseResult<std::string>::fail();
        }

        ss << *it;
        ++it;

        new_line_result = new_line_parser.parse(it, end);
    }
    return svs::ParseResult<std::string>::succeed(ss.str(), new_line_result.next());
}

static svs::ParseResult<std::string> parse_block_comment(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end)
{
    const svs::StringParser comment_begin_parser("/*");
    const svs::StringParser comment_end_parser("*/");

    svs::ParseResult<std::string> comment_start_result = comment_begin_parser.parse(begin, end);
    if (!comment_start_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    std::string::const_iterator it = comment_start_result.next();
    std::stringstream ss;

    svs::ParseResult<std::string> comment_end_result = comment_end_parser.parse(it, end);
    while (!comment_end_result.succeeded())
    {
        if (it == end)
        {
            return svs::ParseResult<std::string>::fail();
        }

        ss << *it;
        ++it;

        comment_end_result = comment_end_parser.parse(it, end);
    }
    return svs::ParseResult<std::string>::succeed(ss.str(), comment_end_result.next());
}

svs::ParseResult<std::string> svs::CommentParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    svs::ParseResult<std::string> one_line_result = parse_one_line_comment(begin, end);
    if (one_line_result.succeeded())
    {
        return one_line_result;
    }

    svs::ParseResult<std::string> block_result = parse_block_comment(begin, end);
    if (block_result.succeeded())
    {
        return block_result;
    }

    return svs::ParseResult<std::string>::fail();
}
