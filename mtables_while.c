#include <stdio.h>

void main()
{
	int ele, i, product;
	i=1;
	printf("Enter the number : ");
	scanf("%d",&ele);

	while (i<=10)
	{
		product = ele * i;
		printf("%d X %d = %d\n", ele, i, product);
		i +=1;
	}
}