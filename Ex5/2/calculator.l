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

[a-zA-Z]+ {yylval=*yytext;
	  return ID;}

[-+*/^()=&|] {return *yytext;}

"<"|">" {return *yytext;}

">=" {return GTE;}

"<=" {return LTE;}

"!=" {return NE;}

"==" {return EQ;}

"&&" {return AND;}

"||" {return OR;}

"!"  {return NOT;}

[\t] ;

[\n] return 0;

. {yyerror("invalid case");}
%%

int yywrap(void)
{
	return 1;
} 
