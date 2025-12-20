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

%}

%option noyywrap nounput noinput batch debug

%{

#define YY_USER_ACTION loc.columns(yyleng);

%}

%%

%{

yy::location& loc = parser.location_;
loc.step();

%}

[ \t\r]+ loc.step();
\n+      loc.lines(yyleng); loc.step();

    /* Annex B: Keywords */

"automatic"     return yy::parser::make_automatic(loc);
"bit"           return yy::parser::make_bit(loc);
"endmodule"     return yy::parser::make_endmodule(loc);
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

[0-9][0-9_]*s {
  std::string value = text().substr(0, text().length() - 1);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kSeconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*s {
  std::string value = text().substr(0, text().length() - 1);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kSeconds), loc);
}
[0-9][0-9_]*ms {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMilliseconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*ms {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMilliseconds), loc);
}
[0-9][0-9_]*us {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMicroseconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*us {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kMicroseconds), loc);
}
[0-9][0-9_]*ns {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kNanoseconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*ns {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kNanoseconds), loc);
}
[0-9][0-9_]*ps {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kPicoseconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*ps {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kPicoseconds), loc);
}
[0-9][0-9_]*fs {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kFemtoseconds), loc);
}
[0-9][0-9_]*\.[0-9][0-9_]*fs {
  std::string value = text().substr(0, text().length() - 2);
  return yy::parser::make_time_literal(std::make_unique<ast::TimeLiteral>(loc, value, ast::TimeUnit::kFemtoseconds), loc);
}

    /* Numbers */

\'[hH] {
  return yy::parser::make_hex_number(std::make_unique<ast::HexNumber>(loc, ast::Signedness::kUnsigned), loc);
}

    /* Identifiers */

[\\].+[\t\n <<EOF>>] {
  std::string string(yytext);
  string = string.substr(1, string.length() - 2);
  return yy::parser::make_identifier(string, loc);
}

[a-zA-Z_][a-zA-Z0-9_$]* return yy::parser::make_identifier(yytext, loc);

    /* Additional operator tokens */

,  return yy::parser::make_comma(loc);
;  return yy::parser::make_semicolon(loc);
\( return yy::parser::make_left_parenthesis(loc);
\) return yy::parser::make_right_parenthesis(loc);
\/ return yy::parser::make_forward_slash(loc);

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

