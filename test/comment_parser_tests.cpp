#include <gtest/gtest.h>

#include "../src/Parser.h"

TEST(CommentParserTests, EmptyString)
{
    svs::CommentParser parser;
    std::string string = "";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(CommentParserTests, SingleSlash)
{
    svs::CommentParser parser;
    std::string string = "/";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(CommentParserTests, MinimalOneLineForm)
{
    svs::CommentParser parser;
    std::string string = "//";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, ManySlashes)
{
    svs::CommentParser parser;
    std::string string = "////////";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "//////");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, OneLineToEndOfString)
{
    svs::CommentParser parser;
    std::string string = "// This is a comment";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), " This is a comment");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, OneLineToEndOfLineLF)
{
    svs::CommentParser parser;
    std::string string = "// This is a comment\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), " This is a comment");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, OneLineToEndOfLineCRLF)
{
    svs::CommentParser parser;
    std::string string = "// This is a comment\r\n";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), " This is a comment");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, MinimalBlockCommentForm)
{
    svs::CommentParser parser;
    std::string string = "/**/";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), "");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, NoCloseToBlockComment)
{
    svs::CommentParser parser;
    std::string string = "/* This is not a comment! *";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    EXPECT_FALSE(result.succeeded());
}

TEST(CommentParserTests, BasicBlockComment)
{
    svs::CommentParser parser;
    std::string string = "/* This is a comment! */";

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), " This is a comment! ");
    EXPECT_EQ(result.next(), string.end());
}

TEST(CommentParserTests, MultilineCommentBlockComment)
{
    svs::CommentParser parser;

    std::stringstream ss;
    ss << "/* This is a multi-line comment!\n";
    ss << "   I exist! */";

    std::string string = ss.str();

    svs::ParseResult<std::string> result = parser.parse(
        string.begin(),
        string.end());

    ASSERT_TRUE(result.succeeded());
    EXPECT_EQ(result.value(), " This is a multi-line comment!\n   I exist! ");
    EXPECT_EQ(result.next(), string.end());
}
