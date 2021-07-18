%{
#include<stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
%}

id [a-zA-Z_]+
no [0-9]+
ro ("<"|"<="|">"|">="|"=="|"!=")
nl "\n"
sp "\t"|" "

%%
"begin" {return BEG;}
"end" {return END;}
"if" {return IF;}
"then" {return THEN;}
"else" {return ELSE;}
"endif" {return ENDIF;}
{id} {yylval.var=strdup(yytext);return ID;}
{no} {yylval.val=atoi(yytext);return NUM;}
{ro} {return RELOP;}
{nl} {return NL;}
{sp} ;
. return yytext[0];
%%

int yywrap(){return 1;}
