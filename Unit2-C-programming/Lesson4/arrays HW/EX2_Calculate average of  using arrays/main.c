/*
 * main.c
 *EX2_Calculate average of  using arrays
 * Created on: Sep 22, 2023
 * Author: Abdelrahman Wael
 * Description: this program take takes n number of element from user
 * (where,n is specified by user)stores data in an array and calculates the average of those number .
 */

#include<stdio.h>
void main()
{
	int num =0,i;
	float arr[50];
	float sum=0;
	printf("Enter numbers of data");
	fflush(stdout);
	scanf("%d",&num);

	for (i=0;i<num;i++)
	{
		printf("Enter number:\n");
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}

	printf("average :%f\n",sum/num);
}
