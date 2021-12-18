#include <stdio.h>

void readMarks(int* marks[]);
{
	int a;

}

void main()
{
	int stdNo;

	printf("Enter number of students : ");
	scanf("%d",&stdNo);

	int marks[stdNo];
	
	readMarks(&marks[stdNo]);
}