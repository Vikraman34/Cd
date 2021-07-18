#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int operator(char op1,char op2)
{
	int flag=1;
	if(op1=='<')
		if(op2=='=')
			printf("Less than or Equal to\n");
		else
			printf("Less than\n");
	else if(op1=='>')
		if(op2=='=')
			printf("Greater than or Equal to\n");
		else
			printf("Greater than\n");
	else if(op1=='=')
		if(op2=='=')
			printf("Equal to\n");
		else
			printf("Assignment operator\n");
	else if(op1=='!')
		if(op2=='=')
			printf("Not Equal to\n");
		else
			return 0;
	else if(op1=='+' && op2==' ')
		printf("Add\n");
	else if(op1=='-' && op2==' ')
		printf("SUB\n");
	else if(op1=='*')
		printf("MUL\n");
	else if(op1=='/')
		printf("DIV\n");
	else if(op1=='&' && op2=='&')
		printf("AND\n");
	else if(op1=='|' && op2=='|')
		printf("OR\n");
	else if(op1=='!')
		printf("NOT\n");
	else
	{
		flag=0;
	}
	return flag;
}

int identifier(char *x)
{
	if(isalpha(x[0]))
	{
		printf("Identifier\n");
		return 1;
	}	
	else 
		return 0;
}

int constant(char *x)
{
	if(isdigit(x[0]))
	{
		printf("Constant\n");
		return 1;
	}	
	else 
		return 0;
}

int comment(char x,char y)
{
	if(x=='/' && y=='/')
	{
		printf("Single line comment\n");
		return 1;
	}
	else if(x=='/' && y=='*')
	{
		printf("Multiple line comment\n");
		return 1;
	}
	else	
		return 0;
}

int keywords(char *str)
{
	if(str[0]=='#')
	{
		printf("Preprocessor directive\n");
		return 1;
	}
	else if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||    !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
   || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str,    "char") || !strcmp(str, "case") || !strcmp(str, "char")
   || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned")
   || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
   {
	   printf("Keyword\n");
	   return 1;
   }
   else
   {
		int i,j,len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i]=='(')
			{
				for(j=i+1;j<len;j++)
				{
					if(str[j]==')')
					{
						printf("Function\n");
						return 1;
					}
				}
			}
			else if(str[i]=='(' || str[i]==')' || str[i]=='{' || str[i]=='}' || str[i]=='[' || str[i]==']' || str[i]==';' || str[i]==',')
			{
				printf("Special Character\n");
				return 1;
			}
		}
		return 0;
   }
}
void main()
{
	FILE *fp;
	fp=fopen("Sample.txt","r");
	char ch;
	int i,len,count=0,c=0;
	while(!feof(fp))
	{
		char str[100];
		fscanf(fp,"%s",str);
		printf("%s ",str);
		for(i=0;i<100;i++)
		{
			if(keywords(str))
				break;
			else if(comment(str[i],str[i+1]))
				i++;
			else if(operator(str[i],str[i+1]))
				i+=2;
			else if(identifier(str))
				break;
			else if(constant(str))
				break;
			else
				continue;
		}
	}
	fclose(fp);
}
