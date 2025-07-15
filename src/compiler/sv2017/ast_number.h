#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

#include <cstdint>
#include <optional>
#include <vector>

namespace svs::ast::sv2017
{

//
// SystemVerilog logic values (6.3.1)
//
// Enumeration of the four basic logic values in SystemVerilog.
//
typedef enum class LogicValue
{
    //
    // Represents a logic zero or a false condition
    //
    _0,

    //
    // Represents a logic one or a true condition
    //
    _1,

    //
    // Represents an unknown logic value
    //
    _X,

    //
    // Represents a high-impedance state
    //
    _Z,
} logic_value_t;

//
// An integer literal constant
//
typedef struct IntegerLiteralConstant
{
    //
    // The optionally-provided size of the number literal.
    //
    std::optional<uint64_t> size;

    //
    // The signedness of the number.
    //
    bool is_signed;

    //
    // The vector of bits that compose the number.
    //
    std::vector<logic_value_t> bits;

} integer_literal_constant_t;

//
// Value equality for integer literal constants.
//
bool operator==(const IntegerLiteralConstant& lhs, const IntegerLiteralConstant& rhs);

}

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_

