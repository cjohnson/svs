#ifndef SVS_COMPILER_SV2017_AST_H_
#define SVS_COMPILER_SV2017_AST_H_

#include <cstdint>
#include <optional>
#include <string>

namespace svs::ast::sv2017
{

//
// Base visitor class for SystemVerilog 2017
//
class visitor_t;

//
// A number.
//
class number_t
{
  protected:
    //
    // Construct a number.
    //
    number_t();

  public:
    //
    // Destruct a number.
    //
    virtual ~number_t();

    //
    // Accept function for visitor
    //
    virtual void accept(visitor_t &visitor) const;
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
                      std::string __value);

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override;

    //
    // The type of integral number
    //
    const integral_number_type_t &integral_number_type() const;

    //
    // The optionally-provided size of the number literal.
    //
    const std::optional<uint64_t> &size() const;

    //
    // True if the number is signed.
    //
    bool is_signed() const;

    //
    // The value.
    //
    const std::string &value() const;
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
    real_number_t(double __value);

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override;

    //
    // The value of the real number
    //
    double value() const;
};

//
// Value equality for real numbers.
//
bool operator==(const real_number_t &lhs, const real_number_t &rhs);

//
// Base visitor class for SystemVerilog 2017
//
class visitor_t
{
  public:
    //
    // Visit method for number_t
    //
    virtual void visit(const number_t &number);

    //
    // Visit method for integral_number_t
    //
    virtual void visit(const integral_number_t &integral_number);

    //
    // Visit method for real_number_t.
    //
    virtual void visit(const real_number_t &integral_number);
};

} // namespace svs::ast::sv2017

#endif // SVS_COMPILER_SV2017_AST_H_
