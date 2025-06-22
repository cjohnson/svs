#include "comment_parser.h"

svs::ParseResult<std::string> svs::CommentParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    return svs::AnyParser<std::string>(
    {
        std::make_shared<svs::OneLineCommentParser>(),
        std::make_shared<svs::BlockCommentParser>(),
    }).parse(begin, end);
}

svs::ParseResult<std::string> svs::OneLineCommentParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    const svs::ParseResult<std::string> comment_start_result =
        svs::StringParser("//").parse(begin, end);
    if (!comment_start_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    return svs::UntilSuccessParser<char>
    {
        svs::CharacterParser('\n'),
        true,
    }.parse(comment_start_result.next(), end);
}

svs::ParseResult<std::string> svs::BlockCommentParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    const svs::ParseResult<std::string> comment_start_result =
        svs::StringParser("/*").parse(begin, end);
    if (!comment_start_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    return svs::UntilSuccessParser<std::string>
    {
        svs::StringParser("*/"),
        true,
    }.parse(comment_start_result.next(), end);
}
