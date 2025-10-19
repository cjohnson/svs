%{

#include <memory>
#include <string>
#include "parser.h"

%}

%%

\\[^ \t\n<<EOF>>] {
    yylval.string_val = std::make_shared<std::string>(yytext);
    return T_Identifier;
}
[a-zA-Z_][a-zA-Z0-9_$]* {
    yylval.string_val = std::make_shared<std::string>(yytext);
    return T_Identifier;
}

    /* A.9.4 White space */

[ \t\n<<EOF>>] { }
