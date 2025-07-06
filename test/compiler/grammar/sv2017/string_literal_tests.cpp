#include <gtest/gtest.h>

#include "../../../../src/compiler/sv2017/grammar_string_literal.hpp"

#include "../grammar_test_utils.hpp"

using namespace svs::grammar::sv2017;

TEST(SV2017StringLiteralTests, FailsToParseEmptyString)
{
    EXPECT_PARSE_FAILURE<string_literal>("");
}

TEST(SV2017StringLiteralTests, ParsesMinimalForm)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\"", "");
}

TEST(SV2017StringLiteralTests, FailsToParseContainingUnescapedNonPrintingCharacters)
{
    EXPECT_PARSE_FAILURE<string_literal>("\"\n\n\"");
}

TEST(SV2017StringLiteralTests, ParsesEscapedNewlineAndIgnoresNewline)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\\n\"", "");
}

TEST(SV2017StringLiteralTests, ParsesSpecTest1)
{
    EXPECT_PARSE_RESULT<string_literal>(
        "\"Humpty Dumpty sat on a wall. \\\n"
        "Humpty Dumpty had a great fall.\"",

        "Humpty Dumpty sat on a wall. Humpty Dumpty had a great fall.");
}

TEST(SV2017StringLiteralTests, ParsesSpecTest2)
{
    EXPECT_PARSE_RESULT<string_literal>(
        "\"Humpty Dumpty sat on a wall.\\n\\\n"
        "Humpty Dumpty had a great fall.\"",

        "Humpty Dumpty sat on a wall.\n"
        "Humpty Dumpty had a great fall.");
}

TEST(SV2017StringLiteralTests, ParsesNewLineEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\n\"", "\n");
}

TEST(SV2017StringLiteralTests, ParsesTabEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\t\"", "\t");
}

TEST(SV2017StringLiteralTests, ParsesBackslashEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\\\\"", "\\");
}

TEST(SV2017StringLiteralTests, ParsesDoubleQuoteEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\\"\"", "\"");
}

TEST(SV2017StringLiteralTests, ParsesVerticalTabEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\v\"", "\v");
}

TEST(SV2017StringLiteralTests, ParsesFormFeedEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\f\"", "\f");
}

TEST(SV2017StringLiteralTests, ParsesBellEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\a\"", "\a");
}

TEST(SV2017StringLiteralTests, ParsesTripleOctalEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\001\"", "\001");
}

TEST(SV2017StringLiteralTests, ParsesDoubleOctalEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\01\"", std::string(1, (char)01));
}

TEST(SV2017StringLiteralTests, ParsesSingleOctalEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\1\"", std::string(1, (char)01));
}

TEST(SV2017StringLiteralTests, ParsesQuadroupleOctalDigitsInEscapeSequenceAsATripleMatch)
{
    std::string expected(1, (char)0);
    expected += '1';
    EXPECT_PARSE_RESULT<string_literal>("\"\\0001\"", expected);
}

TEST(SV2017StringLiteralTests, ParsesSingleHexEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\x1\"", "\x1");
}

TEST(SV2017StringLiteralTests, ParsesDoubleHexEscapeSequence)
{
    EXPECT_PARSE_RESULT<string_literal>("\"\\x01\"", "\x1");
}

TEST(SV2017StringLiteralTests, ParsesTripleHexDigitsInEscapeSequenceAsADoubleMatch)
{
    std::string expected(1, (char)1);
    expected += 'a';
    EXPECT_PARSE_RESULT<string_literal>("\"\\x01a\"", expected);
}

