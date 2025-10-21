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
            result.push_back(token_info_t{ token, yylval });
        }
    } catch(const std::runtime_error& e) { }
    return result;
}

static inline void EXPECT_IDENTIFIER(const std::string& lexer_input,
                                     const std::string& expected_value) {
    std::vector<token_info_t> tokens = lex_all(lexer_input);
    ASSERT_EQ(tokens.size(), 1);

    const token_info_t& first = tokens.at(0);
    EXPECT_EQ(first.token, yytokentype::identifier_k);
    EXPECT_EQ(*first.val.string, expected_value);
}

static inline void EXPECT_SYSTEM_TF_IDENTIFIER(const std::string& lexer_input,
                                               const std::string& expected_value) {
    std::vector<token_info_t> tokens = lex_all(lexer_input);
    ASSERT_EQ(tokens.size(), 1);

    const token_info_t& first = tokens.at(0);
    EXPECT_EQ(first.token, yytokentype::system_tf_identifier_k);
    EXPECT_EQ(*first.val.string, expected_value);
}

TEST(SV2017SimpleIdentifierTests, ParsesTestsFromSpec) {
    EXPECT_IDENTIFIER("shiftreg_a", "shiftreg_a");
    EXPECT_IDENTIFIER("busa_index", "busa_index");
    EXPECT_IDENTIFIER("error_condition", "error_condition");
    EXPECT_IDENTIFIER("merge_ab", "merge_ab");
    EXPECT_IDENTIFIER("_bus3", "_bus3");
    EXPECT_IDENTIFIER("n$657", "n$657");
}

TEST(SV2017SimpleIdentifierTests, ParsesAtLeast1024Characters) {
    std::string string(1024, 'a');
    EXPECT_IDENTIFIER(string, string);
}

TEST(SV2017EscapedIdentifierTests, ParsesBasicEscapedIdentifier) {
    EXPECT_IDENTIFIER("\\;;;;\n", ";;;;");
}

TEST(SV2017EscapedIdentifierTests, ParsesEscapedIdentifiersFromSpec) {
    EXPECT_IDENTIFIER("\\busa+index ", "busa+index");
    EXPECT_IDENTIFIER("\\-clock\n", "-clock");
    EXPECT_IDENTIFIER("\\***error-condition***\n", "***error-condition***");
    EXPECT_IDENTIFIER("\\net1/\\net2\t", "net1/\\net2");
    EXPECT_IDENTIFIER("\\{a,b}\n", "{a,b}");
    EXPECT_IDENTIFIER("\\a*(b+c)\n", "a*(b+c)");
}

TEST(SV2017SystemTFIdentifierTests, FailsToParseDollarSignFollowedByWhiteSpace) {
    std::vector<token_info_t> tokens = lex_all("$");
    EXPECT_TRUE(tokens.empty());

    tokens = lex_all("$ ");
    EXPECT_TRUE(tokens.empty());

    tokens = lex_all("$\n");
    EXPECT_TRUE(tokens.empty());

    tokens = lex_all("$\n");
    EXPECT_TRUE(tokens.empty());
}

TEST(SV2017SystemTFIdentifierTests, ParsesSetOfSystemVerilogDefinedTasks) {
    EXPECT_SYSTEM_TF_IDENTIFIER("$display", "$display");
    EXPECT_SYSTEM_TF_IDENTIFIER("$bitstoreal", "$bitstoreal");
    EXPECT_SYSTEM_TF_IDENTIFIER("$q_remove", "$q_remove");
}

