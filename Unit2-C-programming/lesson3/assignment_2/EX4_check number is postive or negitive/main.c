/*
 * main.c
 *
 * check number is positive or negative or zero
 */



#include<stdio.h>


void main()
{
	float x;
	printf("enter the number you want to check:\n");
	fflush(stdout);
	scanf("%f",&x);
	if(x>0)
		printf(" %f is  positive",x);
	else if (x<0)
		printf(" %f is  negative",x);
	else
		printf(" you entered zero");
}
