/*
 ============================================================================
 Name        : Q9_Function to take string and reverse it
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
void reverse_string(char arr[]);
int main(void)
{
char a[]="Mohamed gamal";
reverse_string(a);
}
void reverse_string(char arr[])
{   printf("input: %s >> output: ",arr);
	int i=0;
	while (arr[i]!=' ')
	{
		i++;
	}
	printf("%s",&arr[i]);
	printf(" ");
	for (i=0;arr[i]!=' ';i++)
	{
		printf("%c",arr[i]);
	}
}
