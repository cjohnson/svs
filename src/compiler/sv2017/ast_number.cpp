#include "ast_number.h"

using namespace svs::sv2017;

ast::integral_number_t::integral_number_t(
    const std::string& _size,
    type_t _type,
    bool _is_signed,
    const std::string& _value)
    : size(_size),
      type(_type),
      is_signed(_is_signed),
      value(_value) { }

ast::integral_number_t::integral_number_t(
    type_t _type,
    bool _is_signed,
    const std::string& _value)
    : size(std::nullopt),
      type(_type),
      is_signed(_is_signed),
      value(_value) { }

