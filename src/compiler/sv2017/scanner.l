%{

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

#include "parser_impl.h"

%}

%option noyywrap

%%

    /* A.9.3 Identifiers */

[\\].+[\t\n <<EOF>>] {
    std::string string(yytext);
    yylval.string_val = new std::string(string.substr(1, string.length() - 2));

    return T_Identifier;
}
[a-zA-Z_][a-zA-Z0-9_$]* {
    yylval.string_val = new std::string(yytext);
    return T_Identifier;
}

    /* A.9.4 White space */

[ \t\n<<EOF>>] { }

    /* Unrecognized token handling */

.* {
    std::stringstream ss;
    ss << "Unrecognized token: ";
    ss << yytext;
    throw std::runtime_error(ss.str());
}

%%

void yyerror(const char *s) {
    std::printf("ERROR: %s\n", s);
}

