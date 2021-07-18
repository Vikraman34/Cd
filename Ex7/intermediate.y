%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yyerror(char *err);
int yylex(void);
int c=0;
char res[100],temp[50];
%}

%token ID NUM RELOP BEG END IF THEN ELSE ENDIF NL
%union{
    int val;
    char* var;
}

%type<val> NUM E F T
%type<var> ID

%left '<' '>'
  
%right '*' '/'

%left '+' '-'

%left '(' ')'

%%
G: BEG NL S NL END {sprintf(temp,"\n\nSyntactically correct\n");strcat(res,temp);printf("%s",res);return 1;}
S: IF C THEN NL A NL ELSE NL A NL ENDIF
C: X RELOP X
X: ID | NUM
A: ID '=' E ';' {sprintf(temp,"\n%s = t%d",$1,$3);strcat(res,temp);}
E: E '*' T {sprintf(temp,"\nt%d = t%d %s t%d",++c,$1,"*",$3);strcat(res,temp);$$=c;}
 | E '/' T {sprintf(temp,"\nt%d = t%d %s t%d",++c,$1,"/",$3);strcat(res,temp);$$=c;}
 | E '%' T {sprintf(temp,"\nt%d = t%d %s t%d",++c,$1,"%",$3);strcat(res,temp);$$=c;}
 | T {$$=$1;}
T: T '+' F {sprintf(temp,"\nt%d = t%d %s t%d",++c,$1,"+",$3);strcat(res,temp);$$=c;}
 | T '-' F {sprintf(temp,"\nt%d = t%d %s t%d",++c,$1,"-",$3);strcat(res,temp);$$=c;}
 | F {$$=$1;} 
F: ID {sprintf(temp,"\nt%d = %s",++c,$1);strcat(res,temp);$$=c;}
 | NUM {sprintf(temp,"\nt%d = %d",++c,$1);strcat(res,temp);$$=c;}
%%

void main()
{
    yyparse();
    printf("\n");
}

int yyerror(char *err)
{
    printf(" Invalid - %s\n",err);
    exit(0);
}
