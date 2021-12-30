#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, i;
	double sum;
	i = 1;
	sum = 0;

	scanf("%d", &N);

	// This loop adds the square root of every number till N to the sum.

	while (i <= N)
	{
		sum += sqrt(i);
		i++;
	}
	printf("%f\n", sum);
}