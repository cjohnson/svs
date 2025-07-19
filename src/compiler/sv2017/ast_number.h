#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

#include <cstdint>
#include <optional>
#include <string>

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
// The type and format of the integral number (hex, octal, etc.)
//
typedef enum IntegralNumberType
{
    //
    // The integral number is in a decimal format.
    //
    Decimal,

    //
    // The integral number is in an octal format.
    //
    Octal,

    //
    // The integral number is in a binary format.
    //
    Binary,

    //
    // The integral number is in a hexadecimal format.
    //
    Hexadecimal,
} integral_number_type_t;

//
// An integer literal constant
//
typedef struct IntegralNumber
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
    // The value.
    //
    std::string value;
} integral_number_t;

//
// Value equality for integer literal constants.
//
bool operator==(const IntegralNumber& lhs, const IntegralNumber& rhs);

}

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_

