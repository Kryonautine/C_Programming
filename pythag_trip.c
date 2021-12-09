#include <stdio.h>

/*
 * tripfind is a function that finds the first N pythagorean triplets.
 * depending on the value of (num3 * num3 - num2 * num2),
 * it either increases num1,num2 or num3 in order to bring the value
 * closer to (num1 * num1).
*/
void tripfind(int *N)
{
	// (3,4,5) is the smallest pythagorean triplet. nCheck is the number of pythagorean triplets printed.
	int num1=3, num2=4, num3=5, nCheck =0;
	while (nCheck < *N)
	{
		if (num3 * num3 - num2 * num2 >= num1 * num1)
		{
			if (num3 * num3 - num2 * num2 == num1 * num1)
			{
				printf("(%d,%d,%d)\n", num1, num2, num3);
				nCheck++;

				/* 
				 * if (num3-num2)= 1, then we can assume that there are no more pythagorean triplets
				 * including num1 that are greater than (current) num2,num3 because then for all values
				 *  greater , (num3*num3 - num2*num2) > num1*num1.
				*/

				if (num3 - num2 == 1)
				{
					num1+=1;
					num2 = num1 + 1;
					num3 = num1 + 2;
				}
				else
				{
					num3 +=1;
				}
			}
			else
			{

				/* 
				 * if (num3-num2)= 1, then we can assume that there are no more pythagorean triplets
				 * including num1 that are greater than (current) num2,num3 because then for all values
				 * (num3*num3 - num2*num2) > num1*num1.
				*/

				if (num3 - num2 == 1)
				{
					num1 +=1;
					num2 = num1 + 1;
					num3 = num1 + 2;
				}
				else
				{
					num2+=1;
				}
			}

		}
		else
		{
			num3+=1;
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