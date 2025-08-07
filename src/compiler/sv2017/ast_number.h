#ifndef SVS_COMPILER_SV2017_AST_NUMBER_H_
#define SVS_COMPILER_SV2017_AST_NUMBER_H_

#include <cstdint>
#include <optional>
#include <string>

#include "ast_visitor.h"

namespace svs::ast::sv2017
{

//
// A number.
//
class number_t
{
  protected:
    //
    // Construct a number.
    //
    number_t()
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
        : _type(__type), _size(__size), _is_signed(__is_signed), _value(__value)
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

//
// A real number
//
class real_number_t : public number_t
{
  private:
    double _value;

  public:
    //
    // Construct a real number.
    //
    real_number_t(double __value) : _value(__value)
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
    // The value of the real number
    //
    double value() const
    {
        return _value;
    }
};

//
// Value equality for real numbers.
//
bool operator==(const real_number_t &lhs, const real_number_t &rhs);

} // namespace svs::ast::sv2017

#endif // SVS_COMPILER_SV2017_AST_NUMBER_H_
