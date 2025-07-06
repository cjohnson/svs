#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

namespace svs::ast::sv2017
{

//
// A logic value.
//
enum class logic_value
{
    LOGIC_0,
    LOGIC_1,
    LOGIC_X,
    LOGIC_Z,
    LOGIC_INVALID,
};

//
// The signedness metadata for the number.
//
enum class signedness
{
    //
    // Indicator that the number is signed.
    //
    SIGNED,

    //
    // Indicator that the number is unsigned.
    //
    UNSIGNED,
};

}

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_
