#ifndef SVS_COMPILER_SV2017_AST_H_
#define SVS_COMPILER_SV2017_AST_H_

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
// Contains information about an integral number base
//
struct integral_number_base_info_t
{
    //
    // Indicates the signedness of the base
    //
    std::optional<char> signedness_indicator;

    //
    // Indicates the base
    //
    char base_indicator;
};

//
// Value equality for integral number base information
//
bool operator==(const integral_number_base_info_t &lhs,
                const integral_number_base_info_t &rhs);

//
// An integral number
//
class integral_number_t : public number_t
{
  private:
    std::optional<std::string> _size;
    std::optional<integral_number_base_info_t> _base_info;
    std::string _value;

  public:
    //
    // Construct an integral number.
    //
    integral_number_t(std::optional<std::string> __size,
                      std::optional<integral_number_base_info_t> __base_info,
                      std::string __value);

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override;

    //
    // The size of the number
    //
    const std::optional<std::string> &size() const;

    //
    // The information about the base
    //
    const std::optional<integral_number_base_info_t> &base_info() const;

    //
    // The value of the number
    //
    const std::string &value() const;
};

//
// Value equality for integral numbers.
//
bool operator==(const integral_number_t &lhs, const integral_number_t &rhs);

//
// Contains information about a fixed point number.
//
struct fixed_point_number_info_t
{
    //
    // The integer part of the fixed point number
    //
    std::string integer_part;

    //
    // The fractional part of the fixed point number
    //
    std::string fractional_part;
};

//
// Value equality for fixed point number infos.
//
bool operator==(const fixed_point_number_info_t &lhs,
                const fixed_point_number_info_t &rhs);

//
// A real number
//
class real_number_t : public number_t
{
  private:
    std::string _integer_part;
    std::optional<std::string> _fractional_part;
    std::optional<std::string> _exponent;

  public:
    //
    // Construct a real number.
    //
    real_number_t(std::string __integer_part,
                  std::optional<std::string> __fractional_part,
                  std::optional<std::string> __exponent);

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override;

    //
    // The integer part of the real number
    //
    const std::string &integer_part() const;

    //
    // The fractional part of the number
    //
    const std::optional<std::string> &fractional_part() const;

    //
    // The exponent of the real number
    //
    const std::optional<std::string> &exponent() const;
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
