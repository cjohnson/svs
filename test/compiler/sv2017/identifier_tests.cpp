#include <vector>

#include <sv2017/scanner.h>

#include <gtest/gtest.h>

struct token_info_t {
    yytokentype token;
    YYSTYPE val;
};
std::vector<token_info_t> lex_all(const std::string& input) {
    svs::sv2017::string_scanner scanner{input};
    std::vector<token_info_t> result;

    try {
        yytokentype token;
        while (scanner >> token) {
            switch (token) {
            case T_Identifier:
                result.push_back(token_info_t{ token, yylval.string_val });
                break;
            default:
                break;
            }
        }
    } catch(const std::runtime_error& e) {
    }
    return result;
}

TEST(SV2017SimpleIdentifierTests, FailsToParseEmptyString) {
    std::vector<token_info_t> tokens = lex_all("");
    EXPECT_TRUE(tokens.empty());
}

TEST(SV2017SimpleIdentifierTests, FailsToParseDollarSign) {
    std::vector<token_info_t> tokens = lex_all("$");
    EXPECT_TRUE(tokens.empty());
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDigit) {
    std::vector<token_info_t> tokens = lex_all("7notident");
    EXPECT_TRUE(tokens.empty());
}

TEST(SV2017SimpleIdentifierTests, FailsToParseStartingWithDollarSign) {
    std::vector<token_info_t> tokens = lex_all("$display");
    EXPECT_TRUE(tokens.empty());
}

void EXPECT_IDENTIFIER(const std::string& lexer_input, const std::string& expected_value) {
    std::vector<token_info_t> tokens = lex_all(lexer_input);
    EXPECT_EQ(tokens.size(), 1);

    const token_info_t& first = tokens.at(0);
    EXPECT_EQ(first.token, yytokentype::T_Identifier);
    EXPECT_EQ(*first.val.string_val, expected_value);
}

TEST(SV2017SimpleIdentifierTests, ParsesTestsFromSpec) {
    EXPECT_IDENTIFIER("shiftreg_a", "shiftreg_a");
    EXPECT_IDENTIFIER("busa_index", "busa_index");
    EXPECT_IDENTIFIER("error_condition", "error_condition");
    EXPECT_IDENTIFIER("merge_ab", "merge_ab");
    EXPECT_IDENTIFIER("_bus3", "_bus3");
    EXPECT_IDENTIFIER("n$657", "n$657");
}

TEST(SV2017SimpleIdentifierTests, ParsesAtLeast1024Characters)
{
    std::string string(1024, 'a');
    EXPECT_IDENTIFIER(string, string);
}

