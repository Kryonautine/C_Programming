#include <stdio.h>

// Do n-dimensional vectors.

void main()
{

	int dimension, dotProduct = 0, i=0;

	printf("Enter number of dimensions of vector : ");
	scanf("%d", &dimension);

	int vec1[dimension], vec2[dimension];

	for (i=0;i<dimension;i++)
	{
		printf("Enter the value of component %d of 1st vector : ", i+1);
		scanf("%d", &vec1[i]);
	}

	for (i=0;i<dimension;i++)
	{
		printf("Enter the value of component %d of 2nd vector : ", i+1);
		scanf("%d", &vec2[i]);
	}

	for (i=0;i<dimension;i++)
	{
		dotProduct += vec1[i]*vec2[i];
	}

	printf("The dot product of vectors \n");

	for (i=0;i<dimension;i++)
	{
		printf("%d ",vec1[i]);
	}

	printf("\nand \n");

	for (i=0;i<dimension;i++)
	{
		printf("%d ",vec2[i]);
	}

	printf("\nis : %d\n", dotProduct);

}