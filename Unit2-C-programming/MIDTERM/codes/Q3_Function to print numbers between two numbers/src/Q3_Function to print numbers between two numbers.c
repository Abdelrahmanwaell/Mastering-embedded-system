/*
 ============================================================================
 Name        : Q3_Function to print numbers between two numbers
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void Print_prime(int min,int max);

int main(void)
{
Print_prime(1,20);
}
void Print_prime(int min,int max)

{   int i,j,count=0;
    printf("input n1=%d , n2=%d >> output:",min,max);
	for(i=min;i<=max;i++)
	{  count=0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0)
			 count++;

		}
	if(count==2)
	{

		printf("%d ",i);
	}
	}
}
