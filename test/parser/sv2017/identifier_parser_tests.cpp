#include <lexy/action/match.hpp>
#include <lexy/action/parse.hpp>
#include <lexy/input/string_input.hpp>
#include <lexy_ext/report_error.hpp>

#include <gtest/gtest.h>
#include <sstream>

#include "../../../src/parser/sv2017/identifier_parser.h"
#include "../../../src/parser/sv2017_grammar.h"

const std::string digits = "0123456789";
const std::string lowercase_alphabet = "abcdefghijklmnopqrstuvwxyz";
const std::string uppercase_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const std::string allowed_first_characters = lowercase_alphabet
    + uppercase_alphabet
    + '_';
const std::string allowed_post_first_characters = lowercase_alphabet
    + uppercase_alphabet
    + digits
    + '_'
    + '$';

/**
 * Expect the identifier parser to succeed against the provided string.
 *
 * Keyword Arguments:
 * input_string: The input to the parser.
 * expected_value: The expected value returned from the parser.
 */
template<typename IdentifierProduction>
static inline void EXPECT_IDENTIFIER_PARSER_SUCCESS(
    const std::string& input_string,
    const std::string& expected_value)
{
    auto string = lexy::string_input(input_string);
    auto result = lexy::parse<IdentifierProduction>(
        string,
        lexy_ext::report_error);

    EXPECT_TRUE(result.is_success());

    if (!result.has_value())
    {
        FAIL() << "Parsing result did not have a value!";
        return;
    }
    EXPECT_EQ(result.value(), expected_value);
}

/**
 * Expect the identifier parser to succeed against the provided string.
 *
 * Keyword Arguments:
 * input_string: The input to the parser and the string expected
 *               to be returned from the parser.
 */
template<typename IdentifierProduction>
static inline void EXPECT_IDENTIFIER_PARSER_SUCCESS(
    const std::string& input_string)
{
    return EXPECT_IDENTIFIER_PARSER_SUCCESS<IdentifierProduction>(
        input_string,
        input_string);
}

/**
 * Expect the identifier parser to fail against the provided string.
 *
 * Keyword Arguments:
 * input_string: The input to the parser.
 */
template<typename IdentifierProduction>
static inline void EXPECT_IDENTIFIER_PARSER_FAILURE(
    const std::string& input_string)
{
    auto string = lexy::string_input(input_string);
    auto result = lexy::parse<IdentifierProduction>(
        string,
        lexy_ext::report_error);

    EXPECT_FALSE(result.is_success());
    EXPECT_FALSE(result.has_value());
}

TEST(EscapedIdentifierParserTests, EmptyStringTest)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(EscapedIdentifierParserTests, EmptyIdentifierTest)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "");
}

TEST(EscapedIdentifierParserTests, BasicTest)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\;;;;\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), ";;;;");
}

TEST(EscapedIdentifierParserTests, SpecTest1)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\busa+index\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "busa+index");
}

TEST(EscapedIdentifierParserTests, SpecTest2)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\-clock\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "-clock");
}

TEST(EscapedIdentifierParserTests, SpecTest3)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\***error-condition***\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "***error-condition***");
}

TEST(EscapedIdentifierParserTests, SpecTest4)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\net1/\\net2\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "net1/\\net2");
}

TEST(EscapedIdentifierParserTests, SpecTest5)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\{a,b}\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "{a,b}");
}

TEST(EscapedIdentifierParserTests, SpecTest6)
{
    svs::EscapedIdentifierParser parser;
    std::string string = "\\a*(b+c)\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "a*(b+c)");
}

TEST(IdentifierParseTests, BasicSimpleIdentifierTest)
{
    svs::IdentifierParser parser;
    std::string string = "tail_ptr";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "tail_ptr");
}

TEST(IdentifierParseTests, BasicEscapedIdentifierTest)
{
    svs::IdentifierParser parser;
    std::string string = "\\we'ra;ravj.....";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "we'ra;ravj.....");
}


TEST(SimpleIdentifierParserTests, EmptyStringTest)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::simple_identifier>("");
}

TEST(SimpleIdentifierParserTests, CannotStartWithDollarSign)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::simple_identifier>("$");
}

TEST(SimpleIdentifierParserTests, DoesNotRecognizeSystemTaskOrFunction)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::simple_identifier>("$display()");
}

TEST(SimpleIdentifierParserTests, CannotStartWithDigit)
{
    for (const char& character : digits)
    {
        auto string = std::string{character};
        EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::simple_identifier>(string);
    }
}

TEST(SimpleIdentifierParserTests, AllowedOneCharacterIdentifiersTest)
{
    for (const char& first_character : allowed_first_characters)
    {
        auto string = std::string{first_character};
        EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>(string);
    }
}

TEST(SimpleIdentifierParserTests, AllowedTwoCharacterIdentifiersTest)
{
    for (const char& first_character : allowed_first_characters)
    {
        for (const char& second_character : allowed_post_first_characters)
        {
            auto string = std::string{first_character, second_character};
            EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>(string);
        }
    }
}

TEST(SimpleIdentifierParserTests, SpecTests)
{
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("shiftreg_a");
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("busa_index");
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("error_condition");
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("merge_ab");
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("_bus3");
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>("n$657");
}

TEST(SimpleIdentifierParserTests, ShallBeAtLeast1024Characters)
{
    std::stringstream ss;
    for (int i = 0; i < 1024; ++i)
    {
        ss << 'a';
    }

    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::simple_identifier>(ss.str());
}

TEST(SystemTaskOrFunctionIdentifierParserTests, EmptyStringTest)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::system_tf_identifier>("");
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DollarSignOnlyTest)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::system_tf_identifier>("$");
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DollarSignCannotBeFollowedByWhiteSpace)
{
    EXPECT_IDENTIFIER_PARSER_FAILURE<sv2017::system_tf_identifier>("$\n");
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DisplayTest)
{
    EXPECT_IDENTIFIER_PARSER_SUCCESS<sv2017::system_tf_identifier>(
        "$display()",
        "display");
}

