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
    EXPECT_THROW(s >> token, std::runtime_error);
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDigit)
{
    svs::sv2017::string_scanner s{"7notident"};

    yytokentype token;
    EXPECT_THROW(s >> token, std::runtime_error);
}

