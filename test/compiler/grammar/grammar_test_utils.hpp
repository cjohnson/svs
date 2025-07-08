#include <lexy/input/string_input.hpp>
#include <lexy/action/parse.hpp>
#include <lexy_ext/report_error.hpp>

#include <gtest/gtest.h>

template<typename TProduction>
static inline void EXPECT_PARSE_SUCCESS(std::string string_input)
{
    auto input = lexy::string_input(string_input);
    EXPECT_TRUE(lexy::match<TProduction>(input))
        << "Expected string \"" << string_input << "\" to be parsed successfully.";
}

template<typename TProduction, typename TResult>
static inline void EXPECT_PARSE_RESULT(std::string string_input, TResult expected)
{
    auto input = lexy::string_input(string_input);
    auto result = lexy::parse<TProduction>(input, lexy_ext::report_error);

    ASSERT_TRUE(result.has_value())
        << "Expected string \"" << string_input << "\" to be parsed successfully.";

    EXPECT_EQ(result.value(), expected);
}

template<typename TProduction>
static inline void EXPECT_PARSE_FAILURE(std::string string_input)
{
    auto input = lexy::string_input(string_input);
    EXPECT_FALSE(lexy::match<TProduction>(input))
        << "Expected string \"" << string_input << "\" to fail to be parsed.";
}

