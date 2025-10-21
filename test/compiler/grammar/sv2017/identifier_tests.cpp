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

