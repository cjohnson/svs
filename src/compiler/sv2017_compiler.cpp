#include <lexy/input/string_input.hpp>
#include <lexy/action/parse.hpp>
#include <lexy_ext/report_error.hpp>

#include "grammar/sv2017.hpp"
#include "sv2017_compiler.h"

std::optional<std::uint32_t> svsc::sv2017_compiler::compile(std::string string_input)
{
    auto input = lexy::string_input(string_input);
    auto result = lexy::parse<sv2017::ipv4_address>(input, lexy_ext::report_error);

    if (!result.has_value())
    {
        return std::nullopt;
    }
    return result.value();
}
