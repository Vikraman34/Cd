#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char input[20][50];
	int i,count,flag=0;
	printf("Enter the number of productions : ");
	scanf(" %d",&count);
	
	for(i=0;i<count;i++)
	{
		printf("\n %d : ",i+1);
		scanf(" %s",input[i]);	
	}
	
	printf("\n\nGrammar:\n");
	for(i=0;i<count;i++)
	{
		printf("%d : %s\n",i+1,input[i]);
		if(input[i][0]==input[i][3])
			flag=1;
	}
	
	if(flag==1)
		printf("\nLeft Recursive\n");
	else
		printf("\nNo Left Recursion\n");
}

