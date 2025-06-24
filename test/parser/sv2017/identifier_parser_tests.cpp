#include <gtest/gtest.h>
#include <sstream>

#include "../../../src/parser/sv2017/identifier_parser.h"

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
    svs::SimpleIdentifierParser parser;
    std::string string = "";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SimpleIdentifierParserTests, CannotStartWithDollarSign)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "$";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SimpleIdentifierParserTests, DoesNotRecognizeSystemTaskOrFunction)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "$display()";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SimpleIdentifierParserTests, CannotStartWithDigit)
{
    svs::SimpleIdentifierParser parser;

    for (const char& character : digits)
    {
        std::string string{character};
        svs::ParseResult<std::string> result = parser.parse(
            string.begin(),
            string.end());

        EXPECT_FALSE(result.succeeded());
    }
}

TEST(SimpleIdentifierParserTests, AllowedOneCharacterIdentifiersTest)
{
    svs::SimpleIdentifierParser parser;

    for (const char& first_character : allowed_first_characters)
    {
        std::string string{first_character};
        svs::ParseResult<std::string> result = parser.parse(
            string.begin(),
            string.end());

        ASSERT_TRUE(result.succeeded());
        EXPECT_EQ(result.next(), string.end());
        EXPECT_EQ(result.value(), string);
    }
}

TEST(SimpleIdentifierParserTests, AllowedTwoCharacterIdentifiersTest)
{
    svs::SimpleIdentifierParser parser;

    for (const char& first_character : allowed_first_characters)
    {
        for (const char& second_character : allowed_post_first_characters)
        {
            std::string string{first_character, second_character};
            svs::ParseResult<std::string> result = parser.parse(
                string.begin(),
                string.end());

            ASSERT_TRUE(result.succeeded());
            EXPECT_EQ(result.next(), string.end());
            EXPECT_EQ(result.value(), string);
        }
    }
}

TEST(SimpleIdentifierParserTests, SpecTest1)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "shiftreg_a";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "shiftreg_a");
}

TEST(SimpleIdentifierParserTests, SpecTest2)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "busa_index";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "busa_index");
}

TEST(SimpleIdentifierParserTests, SpecTest3)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "error_condition";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "error_condition");
}

TEST(SimpleIdentifierParserTests, SpecTest4)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "merge_ab";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "merge_ab");
}

TEST(SimpleIdentifierParserTests, SpecTest5)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "_bus3";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "_bus3");
}

TEST(SimpleIdentifierParserTests, SpecTest6)
{
    svs::SimpleIdentifierParser parser;
    std::string string = "n$657";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
    EXPECT_EQ(result.value(), "n$657");
}

TEST(SimpleIdentifierParserTests, ShallBeAtLeast1024Characters)
{
    svs::SimpleIdentifierParser parser;

    std::stringstream ss;
    for (int i = 0; i < 1024; ++i)
    {
        ss << 'a';
    }
    std::string string = ss.str();

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_EQ(result.next(), string.end());
}

TEST(SystemTaskOrFunctionIdentifierParserTests, EmptyStringTest)
{
    svs::SystemTaskOrFunctionIdentifierParser parser;
    std::string string = "";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DollarSignOnlyTest)
{
    svs::SystemTaskOrFunctionIdentifierParser parser;
    std::string string = "$";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DollarSignCannotBeFollowedByWhiteSpace)
{
    svs::SystemTaskOrFunctionIdentifierParser parser;
    std::string string = "$\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(SystemTaskOrFunctionIdentifierParserTests, DisplayTest)
{
    svs::SystemTaskOrFunctionIdentifierParser parser;
    std::string string = "$display()";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    ASSERT_NE(result.next(), string.end());
    EXPECT_EQ(*result.next(), '(');
    EXPECT_EQ(result.value(), "display");
}

