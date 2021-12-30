#include <stdio.h>

int main(void)
{

	int num1, num2, divsor, divded, hcf, rem=1;

	scanf("%d",&num1);
	scanf("%d",&num2);

	// minum is the smaller of the 2 numbers.

	if (num1 > num2)
	{
		divsor = num2;
		divded = num1;
	}
	else
	{
		divsor = num1;
		divded = num2;
	}

	// Using Euclid's division lemma to find coprime nature.

	while (rem != 0)
	{
		rem = divded % divsor;
		divded = divsor;
		divsor = rem;
	}

	hcf = divded;

	if (hcf != 1)
		printf("NO");
	else
		printf("YES");
}