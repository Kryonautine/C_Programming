#include <stdio.h>

void tripfind(int *N)
{
	int a=3, b=4, c=5, nCheck =0;
	while (nCheck < *N)
	{
		if (c * c - b * b >= a * a)
		{
			if (c * c - b * b == a * a)
			{
				printf("(%d,%d,%d)\n", a, b, c);
				nCheck++;
				if (c - b == 1)
				{
					a++;
					b = a + 1;
					c = a + 2;
				}
				else
				{
					c +=1;
				}
			}
			else
			{
				if (c - b == 1)
				{
					a +=1;
					b = a + 1;
					c = a + 2;
				}
				else
				{
					b+=1;
				}
			}

		}
		else
		{
			c+=1;
		}
	}
}

// ascend() is a function that takes in 3 numbers, and arranges them in ascending order(without using temporary variables).

void ascend(int *num1, int *num2, int *num3)
{
	if (*num1 > *num2)
	{
		*num2 = *num2 + *num1;
		*num1 = *num2 - *num1;
		*num2 = *num2 - *num1;
	}
	if (*num2 > *num3)
	{
		*num3 = *num3 + *num2;
		*num2 = *num3 - *num2;
		*num3 = *num3 - *num2;
	}
	if (*num1 > *num2)
	{
		*num2 = *num2 + *num1;
		*num1 = *num2 - *num1;
		*num2 = *num2 - *num1;
	}
}

void main()
{
	int onum1, onum2, onum3, num1, num2, num3, choice, N;

	// onum* is used to preserve the original input numbers from being changed during execution of ascend().

	printf("Enter 0 for checking whether a given triplet is a pythagorean triplet.\nEnter 1 to find first N Pythagorean triplets.\n");
	scanf("%d", &choice);

	if (choice != 0)
	{
		printf("Enter the number of pythagorean triplets to find : ");
		scanf("%d", &N);

		tripfind(&N);
	}
	else
	{
		printf("Enter the 1st number:");
		scanf("%d", &onum1);
		num1 = onum1;

		printf("Enter the 2nd number:");
		scanf("%d", &onum2);
		num2 = onum2;

		printf("Enter the 3rd number:");
		scanf("%d", &onum3);
		num3 = onum3;

		ascend(&num1, &num2, &num3);

		if (num1 * num1 + num2 * num2 == num3 * num3)
		{
			printf("(%d,%d,%d) is a pythagorean triplet.\n", onum1, onum2, onum3);
		}
		else
		{
			printf("(%d,%d,%d) is not a pythagorean triplet.\n", onum1, onum2, onum3);
		}
	}
}