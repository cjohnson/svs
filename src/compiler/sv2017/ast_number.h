#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

#include <cstdint>
#include <optional>
#include <string>

#include "ast_visitor.h"

namespace svs::ast::sv2017
{

//
// The type of the number
//
enum class number_type_t
{
    //
    // The number is an integral number
    //
    Integral,

    //
    // The number is a real number
    //
    Real,
};

//
// A number.
//
class number_t
{
  private:
    number_type_t _type;

  protected:
    //
    // Construct a number.
    //
    number_t(const number_type_t &__type) : _type(__type)
    {
    }

  public:
    //
    // Destruct a number.
    //
    virtual ~number_t() = default;

    //
    // Accept function for visitor
    //
    virtual void accept(visitor_t &visitor) const
    {
        visitor.visit(*this);
    }

    //
    // Get the type of the number.
    //
    const number_type_t &number_type() const
    {
        return _type;
    }
};

//
// The type and format of the integral number (hex, octal, etc.)
//
enum class integral_number_type_t
{
    //
    // The integral number value is in a decimal format.
    //
    Decimal,

    //
    // The integral number value is in an octal format.
    //
    Octal,

    //
    // The integral number value is in a binary format.
    //
    Binary,

    //
    // The integral number value is in a hexadecimal format.
    //
    Hexadecimal,
};

//
// An integral number
//
class integral_number_t : public number_t
{
  private:
    integral_number_type_t _type;
    std::optional<uint64_t> _size;
    bool _is_signed;
    std::string _value;

  public:
    //
    // Construct an integral number.
    //
    integral_number_t(integral_number_type_t __type,
                      std::optional<uint64_t> __size, bool __is_signed,
                      std::string __value)
        : number_t(number_type_t::Integral), _type(__type), _size(__size),
          _is_signed(__is_signed), _value(__value)
    {
    }

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override
    {
        number_t::accept(visitor);
        visitor.visit(*this);
    }

    //
    // The type of integral number
    //
    const integral_number_type_t &integral_number_type() const
    {
        return _type;
    }

    //
    // The optionally-provided size of the number literal.
    //
    const std::optional<uint64_t> &size() const
    {
        return _size;
    }

    //
    // True if the number is signed.
    //
    bool is_signed() const
    {
        return _is_signed;
    }

    //
    // The value.
    //
    const std::string &value() const
    {
        return _value;
    }
};

//
// Value equality for integral numbers.
//
bool operator==(const integral_number_t &lhs, const integral_number_t &rhs);

} // namespace svs::ast::sv2017

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_
