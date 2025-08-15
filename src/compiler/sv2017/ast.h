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
    std::optional<std::string> _signedness_indicator;
    std::optional<std::string> _base_indicator;
    std::string _value;

  public:
    //
    // Construct an integral number.
    //
    integral_number_t(std::optional<std::string> __size,
                      std::optional<std::string> __signedness_indicator,
                      std::string __base_indicator, std::string __value);

    //
    // Accept function for visitor
    //
    void accept(visitor_t &visitor) const override;

    //
    // The size of the number
    //
    const std::optional<std::string> &size() const;

    //
    // Indicates if the number is signed
    //
    const std::optional<std::string> &signedness_indicator() const;

    //
    // Indicates the base of the number (hex, octal, etc)
    //
    const std::optional<std::string> &base_indicator() const;

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
