#include <stdio.h>

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

int main(void)
{
	int onum1, onum2, onum3, num1, num2, num3;

	// onum* is used to preserve the original input numbers from being changed during execution of ascend().

	scanf("%d", &onum1);
	num1 = onum1;

	scanf("%d", &onum2);
	num2 = onum2;

	scanf("%d", &onum3);
	num3 = onum3;

	ascend(&num1, &num2, &num3);

	if (num1 * num1 + num2 * num2 == num3 * num3)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}