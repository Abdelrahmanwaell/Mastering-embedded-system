/*
 ============================================================================
 Name        : Q2_Funtion to calculate square root of number
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>

float square_root(int x)
{
	return sqrt(x);
}
int main(void)
{
	int x=4,y=10;
	printf("input: %d >> output: %.3f\n",x,sqrt(x));
	printf("input: %d >> output: %.3f\n",y,sqrt(y));
}
