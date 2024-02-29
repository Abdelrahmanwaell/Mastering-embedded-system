/*
 ============================================================================
 Name        : Q1_Function to sum all digits in number
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int sum_digits(int x);
void main()
{
	int a=123;
	int b=4565;
	printf("input: %d >>output: %d \n",a,sum_digits(a));
	printf("input: %d >>output: %d \n",b,sum_digits(b));
}
int sum_digits(int x)
{
	int sum=0;
	while (x!=0)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
