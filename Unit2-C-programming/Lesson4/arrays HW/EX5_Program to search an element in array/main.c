/*
 * main.c
 *  Created on: Sep 23, 2023
 * Author: Abdelrahman Wael
 * EX5_Program to search an element in array
 */


# include <stdio.h>


void main()
{

	int arr[50];
	int i,elements;
    int number;

	printf("Enter the number of elements\n");
	fflush(stdout);
	scanf("%d",&elements);

	printf("Enter %d values:\n",elements);

	for(i=0;i<elements;i++)
	{

		fflush(stdout);
		scanf("%d",&arr[i]);

	}

	printf("\nEnter the element to be searched\n");
	fflush(stdout);
	scanf("%d",&number);

	for(i=0;i<elements;i++)
	{
		if(arr[i]==number)
		{
			printf("\nNumber found at location %d",i+1);
			i=0;
			break;
		}
	}
	if(i!=0)
	{
		printf("\nNumber not found ");

	}












}
