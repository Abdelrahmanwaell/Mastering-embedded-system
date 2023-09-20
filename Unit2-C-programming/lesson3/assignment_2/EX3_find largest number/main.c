/*
 * main.c
 *
 *  find largest number among 3 numbers
 */


#include<stdio.h>


void main()
{
	float x,y,z;
	printf("enter3 numbers you want to check:\n");
	fflush(stdout);
	scanf("%f%f%f",&x,&y,&z);

	if (x>y)
	{
		if(x>z)
			printf("largest number is %f",x);
		else
			printf("largest number is %f",z);
	}
	else
	{
		if(y>z)
			printf("largest number is %f",y);
		else
			printf("largest number is %f",z);
	}
}
