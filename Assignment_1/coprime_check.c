#include <stdio.h>

void main()
{

	int num1, num2, divsor, divded, hcf, rem;

	printf("Enter value of number 1 : ");
	scanf("%d",&num1);
	printf("Enter value of number 2 : ");
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
	printf("The greatest common factor of %d and %d is %d.\n", num1, num2, hcf);

	if (hcf != 1)
		printf("%d and %d are not coprime.\n", num1, num2);
	else
		printf("%d and %d are coprime.\n", num1, num2);
}