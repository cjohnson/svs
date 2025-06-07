#include <gtest/gtest.h>
#include <string>

#include "../src/Lexer.h"
#include "../src/lexical_token/OperatorLexicalToken.h"

void operator_only_test(
    const std::string& syntax,
    const svs::OperatorLexicalToken::Type& type)
{
    svs::Lexer lexer;
    std::vector<std::unique_ptr<svs::LexicalToken>> tokens = lexer.lex_file(syntax);
    ASSERT_GT(tokens.size(), 0);
    EXPECT_EQ(tokens.size(), 1);

    const auto expected = svs::OperatorLexicalToken(
        { .line=0, .col=0 },
        type);

    EXPECT_EQ(tokens[0]->to_string(), expected.to_string());
}

TEST(LexerTests, SimpleAssignmentOnlyTest)
{
    operator_only_test("=", svs::OperatorLexicalToken::Type::SimpleAssignment);
}

TEST(LexerTests, AdditionAssignmentOnlyTest)
{
    operator_only_test("+=", svs::OperatorLexicalToken::Type::AdditionAssignment);
}

TEST(LexerTests, SubtractionAssignmentOnlyTest)
{
    operator_only_test("-=", svs::OperatorLexicalToken::Type::SubtractionAssignment);
}

TEST(LexerTests, MultiplicationAssignmentOnlyTest)
{
    operator_only_test("*=", svs::OperatorLexicalToken::Type::MultiplicationAssignment);
}

TEST(LexerTests, DivisionAssignmentOnlyTest)
{
    operator_only_test("/=", svs::OperatorLexicalToken::Type::DivisionAssignment);
}

TEST(LexerTests, AdditionOnlyTest)
{
    operator_only_test("+", svs::OperatorLexicalToken::Type::Addition);
}

TEST(LexerTests, SubtractionOnlyTest)
{
    operator_only_test("-", svs::OperatorLexicalToken::Type::Subtraction);
}

TEST(LexerTests, MultiplicationOnlyTest)
{
    operator_only_test("*", svs::OperatorLexicalToken::Type::Multiplication);
}

TEST(LexerTests, DivisionOnlyTest)
{
    operator_only_test("/", svs::OperatorLexicalToken::Type::Division);
}

