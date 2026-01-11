%{

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

#include "compiler/sv2017/ast/hex_number.h"
#include "compiler/sv2017/ast/time_unit.h"
#include "compiler/sv2017/parser.h"

namespace ast = svs::sv2017::ast;

// Returns yytext as a string
std::string text() { return yytext; }

#define YY_USER_ACTION loc.columns(yyleng);

%}

%option noyywrap nounput noinput batch debug

    /* A.8.7 Numbers */

fixed_point_number       ({unsigned_number}\.{unsigned_number})
unsigned_number          ({decimal_digit}({decimal_digit}|_)*)
hex_value                ({decimal_digit}({hex_digit}|_)*)
decimal_digit            ([0-9])
hex_digit                ({x_digit}|{z_digit}|[0-9a-fA-F])
x_digit                  ([xX])
z_digit                  ([zZ?])

    /* A.9.4 White space */

white_space ([ \t\r\n<<EOF>>])

%%

%{

yy::location& loc = parser.location_;
loc.step();

%}

[ \t\r]+ loc.step();
\n+      loc.lines(yyleng); loc.step();

    /* Annex B: Keywords */

"assign"        return yy::parser::make_assign(loc);
"automatic"     return yy::parser::make_automatic(loc);
"begin"         return yy::parser::make_begin(loc);
"bit"           return yy::parser::make_bit(loc);
"end"           return yy::parser::make_end(loc);
"endmodule"     return yy::parser::make_endmodule(loc);
"initial"       return yy::parser::make_initial(loc);
"inout"         return yy::parser::make_inout(loc);
"input"         return yy::parser::make_input(loc);
"logic"         return yy::parser::make_logic(loc);
"macromodule"   return yy::parser::make_macromodule(loc);
"module"        return yy::parser::make_module(loc);
"output"        return yy::parser::make_output(loc);
"ref"           return yy::parser::make_ref(loc);
"reg"           return yy::parser::make_reg(loc);
"static"        return yy::parser::make_static_(loc);
"timeprecision" return yy::parser::make_timeprecision(loc);
"timeunit"      return yy::parser::make_timeunit(loc);

    /* Time literals */

({unsigned_number}|{fixed_point_number})s {
  std::string value = text().substr(0, yyleng - 1);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kSeconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}
({unsigned_number}|{fixed_point_number})ms {
  std::string value = text().substr(0, yyleng - 2);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMilliseconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}
({unsigned_number}|{fixed_point_number})us {
  std::string value = text().substr(0, yyleng - 2);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMicroseconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}
({unsigned_number}|{fixed_point_number})ns {
  std::string value = text().substr(0, yyleng - 2);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kNanoseconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}
({unsigned_number}|{fixed_point_number})ps {
  std::string value = text().substr(0, yyleng - 2);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kPicoseconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}
({unsigned_number}|{fixed_point_number})fs {
  std::string value = text().substr(0, yyleng - 2);
  auto time_literal = std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kFemtoseconds);
  return yy::parser::make_time_literal(std::move(time_literal), loc);
}

    /* Numbers */

{unsigned_number} return yy::parser::make_unsigned_number(text(), loc);
{hex_value}       return yy::parser::make_hex_value(text(), loc);
\'[hH]            return yy::parser::make_hex_base(ast::Signedness::kUnsigned, loc);
\'[sS][hH]        return yy::parser::make_hex_base(ast::Signedness::kSigned, loc);

    /* Identifiers */

[\\].+{white_space} {
  std::string string(yytext);
  string = string.substr(1, string.length() - 2);
  return yy::parser::make_identifier(string, loc);
}

[a-zA-Z_][a-zA-Z0-9_$]* return yy::parser::make_identifier(yytext, loc);

$[a-zA-Z0-9_$]+ return yy::parser::make_system_tf_identifier(yytext, loc);

    /* Additional operator tokens */

"(*" return yy::parser::make_attribute_instance_begin(loc);
"*)" return yy::parser::make_attribute_instance_end(loc);
,    return yy::parser::make_comma(loc);
=    return yy::parser::make_equals(loc);
;    return yy::parser::make_semicolon(loc);
\(   return yy::parser::make_left_parenthesis(loc);
\)   return yy::parser::make_right_parenthesis(loc);
\/   return yy::parser::make_forward_slash(loc);

<<EOF>> return yy::parser::make_YYEOF(loc);

%%

void svs::sv2017::Parser::BeginScan(const std::string& file_name) {
  yy_flex_debug = scanning_debug_traces_enabled_;
  if (!(yyin = fopen(file_name.c_str(), "r"))) {
    std::cerr << "cannot open " << file_name << ": "
              << strerror(errno) << '\n';
  }
}

void svs::sv2017::Parser::EndScan() {
  fclose(yyin);
}

