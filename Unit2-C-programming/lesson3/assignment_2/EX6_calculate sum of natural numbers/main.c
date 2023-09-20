/*
 * main.c
 *
 *calculate sum of natural numbers
 */


#include <stdio.h>

void main()
{

	int num,sum=0;
	int i;
	printf("enter an intger\n");
	fflush(stdout);
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		sum+=i;
	}


	printf("sum= %d\n",sum);







}
