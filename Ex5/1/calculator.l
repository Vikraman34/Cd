%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
void yyerror(char*);
extern int yylval;

%}


%%
[0-9]+ {
	yylval=atoi(yytext);
	return NUMBER;
}

[-+*/^()] {return *yytext;}

[\t] ;

[\n] return 0;

. {yyerror("invalid case");}
%%

int yywrap(void)
{
	return 1;
} 
