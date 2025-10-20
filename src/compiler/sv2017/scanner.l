%{

#include <iostream>
#include <string>

#include "parser_impl.h"

%}

%option noyywrap

%%


    /* A.9.3 Identifiers */

\\[^ \t\n<<EOF>>] {
    yylval.string_val = new std::string(yytext);
    return T_Identifier;
}
[a-zA-Z_][a-zA-Z0-9_$]* {
    yylval.string_val = new std::string(yytext);
    return T_Identifier;
}

    /* A.9.4 White space */

[ \t\n<<EOF>>] { }

%%

void yyerror(const char *s) {
    std::printf("ERROR: %s\n", s);
}
