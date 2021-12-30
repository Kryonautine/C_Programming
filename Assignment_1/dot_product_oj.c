#include <stdio.h>

int main(void)
{

	long dimension, dotProduct = 0, i=0;

	scanf("%ld", &dimension);

	long vec1[dimension], vec2[dimension];

	// Scanning all values of n-dimensional vector.

	for (i=0;i<dimension;i++)
	{
		scanf("%ld", &vec1[i]);
	}

	for (i=0;i<dimension;i++)
	{
		scanf("%ld", &vec2[i]);
	}

	// Calculating Dot Product of the 2 vectors

	for (i=0;i<dimension;i++)
	{
		dotProduct += vec1[i]*vec2[i];
	}
	
	// Printing original vectors and their dot product.

	printf("%ld", dotProduct);

}