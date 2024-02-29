/*
 ============================================================================
 Name        : Ex4_Store information of student using structure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct sStudent {
	char name[20];
	float marks;
};
int main(void)
{
	int i;
	struct sStudent data [10];

	printf ("Enter information of students:\n");

	for (i=0;i<10;i++)
	{
		printf("\nFor roll number %d\n",i+1);
		printf ("Enter name: ");
		fflush (stdout);
		scanf ("%s",data[i].name);

		printf ("Enter marks: ");
		 fflush (stdout);
		scanf ("%f",&data[i].marks);
	}

	printf ("\nDisplaying information of students:\r\n");

	for (i=0;i<10;i++)
	{
		printf ("information for roll number %d\n",i+1);
		printf ("name: %s\n",data[i].name);
		printf ("Marks: %.1f\r\n",data[i].marks);
	}



	return 0;
}
