#include <stdio.h>

void main()
{
	int ele, product, i;
	i = 1;
	printf("Enter the number : ");
	scanf("%d",&ele);

	loop:
	product = ele * i;
	printf("%d X %d = %d\n", ele, i, product);
	i += 1;
	if (i <= 10)
	goto loop;
}