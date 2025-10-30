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

    /* A.8.7 Numbers */

[xXzZ?0-9a-fA-F][xXzZ?0-9a-fA-F_]* return yy::parser::make_INTEGRAL_NUMBER_VALUE(yytext, loc);

'[sS][dD] return yy::parser::make_DECIMAL_BASE(true, loc);
'[dD]     return yy::parser::make_DECIMAL_BASE(false, loc);
'[sS][bB] return yy::parser::make_BINARY_BASE(true, loc);
'[bB]     return yy::parser::make_BINARY_BASE(false, loc);
'[sS][oO] return yy::parser::make_OCTAL_BASE(true, loc);
'[oO]     return yy::parser::make_OCTAL_BASE(false, loc);
'[sS][hH] return yy::parser::make_HEX_BASE(true, loc);
'[hH]     return yy::parser::make_HEX_BASE(false, loc);

    /* A.8.8 Strings */

\".*\" {
    std::string string(yytext);
    string = string.substr(1, string.length() - 2);
    return yy::parser::make_STRING_LITERAL(string, loc);
}

    /* A.9.3 Identifiers */

        /* escaped_identifier */

[\\].+[\t\n <<EOF>>] {
    std::string string(yytext);
    string = string.substr(1, string.length() - 2);
    return yy::parser::make_IDENTIFIER(string, loc);
}

        /* simple_identifier */

[a-zA-Z_][a-zA-Z0-9_$]* return yy::parser::make_IDENTIFIER(yytext, loc);

        /* system_tf_identifier */

$[a-zA-Z0-9_$]+ return yy::parser::make_SYSTEM_TF_IDENTIFIER(yytext, loc);

<<EOF>> return yy::parser::make_YYEOF(loc);

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

