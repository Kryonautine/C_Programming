#include <stdio.h>
#include <math.h>

void main()
{
	int N, i;
	double sum;
	i =1;
	sum = 0;
	printf("Enter the number : ");
	scanf("%d",&N);
	
	while (i<=N)
	{
		sum += sqrt(i);
		i += 1;
	}
	printf("Sum of square root of all numbers till %d is %f\n", N, sum);
}