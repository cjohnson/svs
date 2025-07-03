#ifndef SVSC_SV2017_COMPILER_H_
#define SVSC_SV2017_COMPILER_H_

#include <cstdint>
#include <optional>
#include <string>

namespace svsc
{

/**
 * SystemVerilog 2017 Compiler
 */
class sv2017_compiler
{
public:
    std::optional<std::uint32_t> compile(std::string input);
};

}

#endif // SVSC_SV2017_COMPILER_H_

