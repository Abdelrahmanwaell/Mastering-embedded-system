/*
 * main.c
 *  Created on: Sep 23, 2023
 * Author:Abdelrahman Wael
 * EX4_Insert element to array
 */

#include<stdio.h>

void main()
{
	int i,element,num,location;
	int arr[100];

	printf("Enter numbers of element: \n");
	fflush(stdout);
	scanf("%d",&element);

	 for(i=0;i<element;i++)
	 {
		 arr[i]=i+1;
		 printf("%d ",arr[i]);

	 }

	printf("\nenter the element to be inserted: \n ");
	fflush(stdout);
	scanf("%d",&num);

	printf("enter the location: \n ");
	fflush(stdout);
	scanf("%d",&location);

	for(i=element;i>location-1;i--)
	{
		arr[i]=arr[i-1];
	}

	arr[location-1]=num;
	for(i=0;i<=element;i++)
	{
		printf("%d ",arr[i]);
	}









}
