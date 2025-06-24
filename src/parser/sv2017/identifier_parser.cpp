#include "identifier_parser.h"
#include "white_space_parser.h"

svs::ParseResult<std::string> svs::EscapedIdentifierParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    const svs::ParseResult<char> leading_backslash_result =
        svs::CharacterParser('\\').parse(begin, end);
    if (!leading_backslash_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }

    return svs::UntilSuccessParser<char>
    {
        svs::WhiteSpaceParser(),
        true,
    }.parse(leading_backslash_result.next(), end);
}

svs::ParseResult<std::string> svs::IdentifierParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    return svs::AnyParser<std::string>(
    {
        std::make_shared<svs::SimpleIdentifierParser>(),
        std::make_shared<svs::EscapedIdentifierParser>(),
    }).parse(begin, end);
}

svs::ParseResult<std::string> svs::SimpleIdentifierParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    std::stringstream ss;

    const svs::ParseResult<char> first_character_result = svs::AnyParser<char>(
    {
        std::make_shared<svs::AlphabeticCharacterParser>(),
        std::make_shared<svs::CharacterParser>('_'),
    }).parse(begin, end);
    if (!first_character_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    ss << first_character_result.value();

    const svs::ParseResult<std::string> remaining_characters_result =
        svs::OptionalParser<std::string>(
            svs::SomeParser<char>(
                std::make_shared<svs::AnyParser<char>>(
                    std::vector<std::shared_ptr<svs::Parser<char>>>
                    {
                        std::make_shared<svs::AlphanumericCharacterParser>(),
                        std::make_shared<svs::CharacterParser>('_'),
                        std::make_shared<svs::CharacterParser>('$'),
                    }))).parse(first_character_result.next(), end);

    ss << remaining_characters_result.value();
    return svs::ParseResult<std::string>::succeed(ss.str(), remaining_characters_result.next());
}

svs::ParseResult<std::string> svs::SystemTaskOrFunctionIdentifierParser::parse(
    const std::string::const_iterator& begin,
    const std::string::const_iterator& end) const
{
    std::stringstream ss;
    std::string::const_iterator it = begin;

    const svs::ParseResult<char> dollar_sign_result = svs::CharacterParser('$').parse(begin, end);
    if (!dollar_sign_result.succeeded())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = dollar_sign_result.next();

    const svs::ParseResult<std::string> remaining_characters_result =
        svs::SomeParser<char>(
            std::make_shared<svs::AnyParser<char>>(
                std::vector<std::shared_ptr<svs::Parser<char>>>
                {
                    std::make_shared<svs::AlphanumericCharacterParser>(),
                    std::make_shared<svs::CharacterParser>('_'),
                    std::make_shared<svs::CharacterParser>('$'),
                })).parse(it, end);
    if (!remaining_characters_result.succeeded() || remaining_characters_result.value().empty())
    {
        return svs::ParseResult<std::string>::fail();
    }
    it = remaining_characters_result.next();
    ss << remaining_characters_result.value();

    return svs::ParseResult<std::string>::succeed(ss.str(), it);
}

