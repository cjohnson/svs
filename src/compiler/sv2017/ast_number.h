#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

#include <optional>
#include <string>
#include <type_traits>

namespace svs::sv2017::ast {

//
// A number.
//
class number_t {};
static_assert(std::is_standard_layout_v<number_t>);

//
// An integral number.
//
class integral_number_t : public number_t {
public:
    //
    // The type of integral number.
    //
    enum class type_t { Decimal, Binary, Octal, Hex };

    //
    // Sized integral number constructor.
    //
    integral_number_t(
        const std::string& _size,
        type_t _type,
        bool _is_signed,
        const std::string& _value);

    //
    // Unsized integral number constructor.
    //
    integral_number_t(
        type_t _type,
        bool _is_signed,
        const std::string& _value);

    //
    // If present, the size of the number.
    //
    std::optional<std::string> size;

    //
    // True if the number is signed.
    //
    bool is_signed;

    //
    // The integral number type.
    //
    type_t type;

    //
    // The integral number value.
    //
    std::string value;
};
static_assert(std::is_standard_layout_v<integral_number_t>);

}

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_

