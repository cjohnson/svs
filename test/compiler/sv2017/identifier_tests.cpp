#include <sv2017/scanner.h>

#include <gtest/gtest.h>

TEST(SV2017SimpleIdentifierTests, FailsToParseEmptyString)
{
    svs::sv2017::string_scanner s{""};

    yytokentype token;
    s >> token;

    EXPECT_FALSE(s);
}

TEST(SV2017SimpleIdentifierTests, FailsToParseDollarSign)
{
    svs::sv2017::string_scanner s{"$"};

    yytokentype token;
    s >> token;

    EXPECT_FALSE(s);
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDigit)
{
    svs::sv2017::string_scanner s{"7notident"};

    yytokentype token;
    s >> token;

    ASSERT_TRUE(s);
    EXPECT_EQ(token, yytokentype::T_Identifier);
    EXPECT_NE(*yylval.string_val, "7notident");
    EXPECT_EQ(*yylval.string_val, "notident");
}

