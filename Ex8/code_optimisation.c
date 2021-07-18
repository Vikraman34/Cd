#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	FILE *fp;
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{	
		char st[100];
		fscanf(fp," %[^\n]",st);
		if(!feof(fp))
		{
			if(st[3]=='+')
			{
				if(st[2]=='0'||st[4]=='0')
				{
					printf("Line Eliminated\n");
				}
				else
					printf("%s\n",st);
			}
			else if(st[3]=='*')
			{
				if(st[2]=='1'||st[4]=='1')
				{
					printf("Line Eliminated\n");
				}
				else
					printf("%s\n",st);
			}
			else if(st[3]=='-')
			{
				if(st[4]=='0')
				{
					printf("Line Eliminated\n");
				}
				else if(st[2]=='0')
				{
					sprintf(st,"%c%c%c%c",st[0],st[1],st[3],st[4]);
					printf("%s\n",st);
				}
				else
					printf("%s\n",st);
			}
			else if(st[3]=='/')
			{
				if(st[4]=='1')
				{
					printf("Line Eliminated\n");
				}
				else if(st[2]=='0')
				{
					sprintf(st,"%c%c0",st[0],st[1]);
					printf("%s\n",st);
				}
				else
					printf("%s\n",st);
			}
			else if(st[2]=='p' && st[3]=='o' && st[4]=='w')
			{
				sprintf(st,"%c%c%c*%c",st[0],st[1],st[6],st[6]);
				printf("%s\n",st);
			}
		}
	}
	fclose(fp);
}



