%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"y.tab.h"
int yylex(void);
void yyerror(char *str);

%}


%token NUMBER 
  
%left '+' '-'
  
%left '*' '/'
  
%right '^'

%left '(' ')'



%%
ArithmeticExpression: E {
	printf("\nResult=%d\n", $$); 
	return 0; 
	}; 

E:E'+'E {$$=$1+$3;} 

|E'-'E {$$=$1-$3;} 

|E'*'E {$$=$1*$3;} 

|E'/'E {$$=$1/$3;} 

|E'^'E {$$=pow($1,$3);}

|'('E')' {$$=$2;} 

| NUMBER {$$=$1;} 

; 
  
%%
  
  
 
void yyerror(char *str)
{ 
   fprintf(stderr,"%s\n",str);
} 


void main() 
{ 
   yyparse(); 
} 
