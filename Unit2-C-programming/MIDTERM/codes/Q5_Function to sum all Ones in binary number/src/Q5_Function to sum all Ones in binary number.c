/*
 ============================================================================
 Name        : Q5_Function to count_ones in binary number
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>



int count_ones(int x);
void main()
{
printf("input:5 >>output: %d\n",count_ones(5));
printf("input:15 >>output: %d\n",count_ones(15));
}
count_ones(int x)
{
	int i;
	int counter=0;
	if(x!=0)
	{
	for(i=0;i<32;i++)
	{
			if(x&1)
			{
				counter++;
				x=x>>1;
			}
			else
			{
				x=x>>1;
			}

	}
	}

return counter;
}
