%{

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

#include "parser.h"

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

    /* Keywords */

endmodule   return yy::parser::make_endmodule(loc);
macromodule return yy::parser::make_macromodule(loc);
module      return yy::parser::make_module(loc);

    /* Identifiers */

[\\].+[\t\n <<EOF>>] {
    std::string string(yytext);
    string = string.substr(1, string.length() - 2);
    return yy::parser::make_identifier(string, loc);
}

[a-zA-Z_][a-zA-Z0-9_$]* return yy::parser::make_identifier(yytext, loc);

    /* Operators */

;  return yy::parser::make_semicolon(loc);
\( return yy::parser::make_left_parenthesis(loc);
\) return yy::parser::make_right_parenthesis(loc);

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

