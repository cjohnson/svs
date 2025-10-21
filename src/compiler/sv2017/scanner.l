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

        /* escaped_identifier */

[\\].+[\t\n <<EOF>>] {
    std::string string(yytext);
    yylval.string = new std::string(string.substr(1, string.length() - 2));

    return identifier_k;
}

        /* simple_identifier */

[a-zA-Z_][a-zA-Z0-9_$]* {
    yylval.string = new std::string(yytext);
    return identifier_k;
}

        /* system_tf_identifier */

$[a-zA-Z0-9_$]+ {
    yylval.string = new std::string(yytext);
    return system_tf_identifier_k;
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

