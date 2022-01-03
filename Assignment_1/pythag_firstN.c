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
				// This if statement is to satisfy condition (a/b/c)<= 200.

				if (num3 <= 200)
				{
					printf("%d %d %d\n", num1, num2, num3);
					nCheck++;
				}

				/* 
				 * if (num3-num2)= 1, then we can assume that there are no more pythagorean triplets
				 * including num1 that are greater than (current) num2,num3 because then for all values
				 *  greater , (num3*num3 - num2*num2) > num1*num1.
				*/

				if (num3 - num2 == 1)
				{
					num1++;
					num2 = num1 + 1;
					num3 = num1 + 2;
				}
				else
				{
					num3++;
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
					num1++;
					num2 = num1 + 1;
					num3 = num1 + 2;
				}
				else
				{
					num2++;
				}
			}

		}
		else
		{
			num3++;
		}
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);

	tripfind(&N);
}