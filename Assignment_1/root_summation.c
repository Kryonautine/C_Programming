#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, i;
	double sum;
	i = 1;
	sum = 0;

	printf("Enter number :");
	scanf("%d", &N);

	// This loop adds the square root of every number till N to the sum.

	while (i <= N)
	{
		sum += sqrt(i);
		i++;
	}
	printf("Sum of square root of all numbers till %d is %f\n", N, sum);
}