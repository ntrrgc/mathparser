%{
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <string>
#include "MathParser.tab.hpp"
#include "MathDriver.hpp"

#define yyterminate() return token::END
%}

%option noyywrap nounput reentrant

id           [a-zA-Z_][a-zA-Z_0-9]*
number       ([0-9]+(\.[0-9]*)?|[0-9]*\.[0-9]+)(e[0-9]+)?
operator     "+"|"-"|"*"|"/"|"^"
parentheses  [()]
punctuation  [,]
blank        [ \t]

%{
#define YY_USER_ACTION yylloc->columns(yyleng);
%}

%%
%{
    yylloc->step();
%}

{blank}+    yylloc->step();

%{
    typedef yy::MathParser::token token;
%}

{operator}|{parentheses}|{punctuation} {
    return static_cast<yy::MathParser::token_type>(yytext[0]);
            }
{number}    {
    double dbl = strtod(yytext, nullptr);
    yylval->numvalue = dbl;
    return token::NUM;
            }
{id}        {
    yylval->strvalue = new std::string(yytext);
    return token::ID;
            }
.           {
    driver.error(*yylloc, "invalid character");
    return token::END;
            }
%%

void
MathDriver::scan_begin() {
    yylex_init(&yyscanner);
    bufferState = yy_scan_string(buffer.c_str(), yyscanner);
}

void
MathDriver::scan_end() {
    yy_delete_buffer(bufferState, yyscanner);
    bufferState = nullptr;
    yylex_destroy(yyscanner);
}
