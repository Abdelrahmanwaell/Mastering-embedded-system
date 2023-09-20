/*
 * main.c
 *
 * Find factorial of a Number
 */


/*
 * main.c
 *
 *calculate sum of natural numbers
 */


#include <stdio.h>

void main()
{

	int num;
	unsigned long fact=1;
	int i;
	printf("enter an intger\n");
	fflush(stdout);
	scanf("%d",&num);

	if(num<0)
	{
		printf("Factorial of negative number doesn't exist \n");
	}
	else if (num>0)
	{
		for(i=1;i<=num;i++)
			{
				fact*=i;
			}
		printf("%d!=%d \n",num,fact);

	}

	else
	{
		printf("0!=1 \n");
	}











}
