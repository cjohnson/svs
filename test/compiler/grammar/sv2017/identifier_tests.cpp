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

TEST(SV2017SimpleIdentifierTests, FailsToParseEmptyString)
{
    EXPECT_PARSE_FAILURE<simple_identifier>("");
}

TEST(SV2017SimpleIdentifierTests, FailsToParseDollarSign)
{
    EXPECT_PARSE_FAILURE<simple_identifier>("$");
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDigit)
{
    EXPECT_PARSE_FAILURE<simple_identifier>("7notident");
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDollarSign)
{
    EXPECT_PARSE_FAILURE<simple_identifier>("$display");
}

TEST(SV2017SimpleIdentifierTests, ParsesTestsFromSpec)
{
    EXPECT_PARSE_RESULT<simple_identifier>("shiftreg_a", "shiftreg_a");
    EXPECT_PARSE_RESULT<simple_identifier>("busa_index", "busa_index");
    EXPECT_PARSE_RESULT<simple_identifier>("error_condition", "error_condition");
    EXPECT_PARSE_RESULT<simple_identifier>("merge_ab", "merge_ab");
    EXPECT_PARSE_RESULT<simple_identifier>("_bus3", "_bus3");
    EXPECT_PARSE_RESULT<simple_identifier>("n$657", "n$657");
}

TEST(SV2017SimpleIdentifierTests, ParsesAtLeast1024Characters)
{
    std::string string(1024, 'a');
    EXPECT_PARSE_RESULT<simple_identifier>(string, string);
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

