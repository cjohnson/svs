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

yy::location& loc = parser.location;
loc.step();

%}

[ \t\r]+ loc.step();
\n+      loc.lines(yyleng); loc.step();

    /* A.1.2 SystemVerilog source text */

module      return yy::parser::make_MODULE(loc);
macromodule return yy::parser::make_MODULE(loc);

endmodule   return yy::parser::make_ENDMODULE(loc);

    /* A.9.3 Identifiers */

        /* escaped_identifier */

[\\].+[\t\n <<EOF>>] {
    std::string string(yytext);
    string = string.substr(1, string.length() - 2);
    return yy::parser::make_IDENTIFIER(string, loc);
}

        /* simple_identifier */

[a-zA-Z_][a-zA-Z0-9_$]* return yy::parser::make_IDENTIFIER(yytext, loc);

<<EOF>> return yy::parser::make_YYEOF(loc);

; return yy::parser::make_SEMICOLON(loc);

%%

void svs::sv2017::parser::scan_begin() {
    yy_flex_debug = trace_scanning;
}

void svs::sv2017::parser::scan_begin(const std::string& file_name) {
    yy_flex_debug = trace_scanning;
    if (!(yyin = fopen(file_name.c_str(), "r"))) {
        std::cerr << "cannot open " << file_name << ": "
                  << strerror(errno) << '\n';
    }
}

void svs::sv2017::parser::scan_end() {
    fclose(yyin);
}

