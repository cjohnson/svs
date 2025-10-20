#include "../../../../src/compiler/sv2017/grammar_identifier.hpp"

#include <gtest/gtest.h>

#include "../grammar_test_utils.hpp"

using namespace svs::sv2017::grammar;

TEST(SV2017SystemTFIdentifierTests, FailsToParseEmptyString)
{
    EXPECT_PARSE_FAILURE<system_tf_identifier>("");
}

TEST(SV2017SystemTFIdentifierTests, FailsToParseWithoutLeadingDollarSign)
{
    EXPECT_PARSE_FAILURE<system_tf_identifier>("simple_identifier");
}

TEST(SV2017SystemTFIdentifierTests, FailsToParseDollarSignFollowedByWhiteSpace)
{
    EXPECT_PARSE_FAILURE<system_tf_identifier>("$");
    EXPECT_PARSE_FAILURE<system_tf_identifier>("$ ");
    EXPECT_PARSE_FAILURE<system_tf_identifier>("$\n");
    EXPECT_PARSE_FAILURE<system_tf_identifier>("$\t");
}

TEST(SV2017SystemTFIdentifierTests, ParsesSetOfSystemVerilogDefinedTasks)
{
    EXPECT_PARSE_RESULT<system_tf_identifier>("$display", "display");
    EXPECT_PARSE_RESULT<system_tf_identifier>("$bitstoreal", "bitstoreal");
    EXPECT_PARSE_RESULT<system_tf_identifier>("$q_remove", "q_remove");
}

TEST(SV2017SystemTFIdentifierTests, ParsesWithWhitespaceAtEnd)
{
    EXPECT_PARSE_RESULT<system_tf_identifier>("$display ", "display");
    EXPECT_PARSE_RESULT<system_tf_identifier>("$display\t", "display");
    EXPECT_PARSE_RESULT<system_tf_identifier>("$display\n", "display");
}

TEST(SV2017EscapedIdentifierTests, FailsToParseEmptyString)
{
    EXPECT_PARSE_FAILURE<escaped_identifier>("");
}

TEST(SV2017EscapedIdentifierTests, ParsesBasicEscapedIdentifier)
{
    EXPECT_PARSE_RESULT<escaped_identifier>("\\;;;;\n", ";;;;");
}

TEST(SV2017EscapedIdentifierTests, ParsesEscapedIdentifiersFromSpec)
{
    EXPECT_PARSE_RESULT<escaped_identifier>("\\busa+index ", "busa+index");
    EXPECT_PARSE_RESULT<escaped_identifier>("\\-clock\n", "-clock");
    EXPECT_PARSE_RESULT<escaped_identifier>("\\***error-condition***\n", "***error-condition***");
    EXPECT_PARSE_RESULT<escaped_identifier>("\\net1/\\net2\n", "net1/\\net2");
    EXPECT_PARSE_RESULT<escaped_identifier>("\\{a,b}\n", "{a,b}");
    EXPECT_PARSE_RESULT<escaped_identifier>("\\a*(b+c)\n", "a*(b+c)");
}

TEST(SV2017IdentifierTests, ParsesBasicSimpleIdentifier)
{
    EXPECT_PARSE_RESULT<identifier>("tail_ptr", "tail_ptr");
}

TEST(SV2017IdentifierTests, ParsesBasicEscapedIdentifier)
{
    EXPECT_PARSE_RESULT<identifier>("\\we'ra;ravj.....", "we'ra;ravj.....");
}

