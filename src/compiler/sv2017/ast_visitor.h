#ifndef SVS_COMPILER_SV2017_AST_VISITOR_H_
#define SVS_COMPILER_SV2017_AST_VISITOR_H_

namespace svs::ast::sv2017
{

class number_t;
class integral_number_t;
class real_number_t;

//
// Base visitor class for SystemVerilog 2017.
//
class visitor_t
{
  public:
    //
    // Visit method for number_t.
    //
    virtual void visit(const number_t &number);

    //
    // Visit method for integral_number_t.
    //
    virtual void visit(const integral_number_t &integral_number);

    //
    // Visit method for real_number_t.
    //
    virtual void visit(const real_number_t &integral_number);
};

} // namespace svs::ast::sv2017

#endif // SVS_COMPILER_SV2017_AST_VISITOR_H_
