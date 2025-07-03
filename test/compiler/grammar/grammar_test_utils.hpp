#include <lexy/input/string_input.hpp>
#include <lexy/action/parse.hpp>
#include <lexy_ext/report_error.hpp>

#include <gtest/gtest.h>

template<typename TProduction, typename TResult>
static inline void EXPECT_PARSE_RESULT(std::string string_input, TResult expected)
{
    auto input = lexy::string_input(string_input);
    auto result = lexy::parse<TProduction>(input, lexy_ext::report_error);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), expected);
}

template<typename TProduction>
static inline void EXPECT_PARSE_RESULT(std::string string_input)
{
    EXPECT_PARSE_RESULT<TProduction>(string_input, string_input);
}

template<typename TProduction>
static inline void EXPECT_PARSE_FAILURE(std::string string_input)
{
    auto input = lexy::string_input(string_input);
    EXPECT_FALSE(lexy::match<TProduction>(input));
}
