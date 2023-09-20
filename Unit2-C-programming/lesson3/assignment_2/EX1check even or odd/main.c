/*
 * program to check if number is even or odd
 *
 *
 */

#include<stdio.h>


void main(){


	int x;
	printf("enter an inter you want to check:\n");
	fflush(stdout);
	scanf("%d",&x);
	if (x % 2==0)
	{
		printf("%d is even",x);
	}
	else
	{
		printf("%d is odd",x);
	}


}
