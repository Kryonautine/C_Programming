#include <stdio.h>

void main()
{
	int ele, i, product, rows;
	i = 1;
	printf("Enter the number : ");
	scanf("%d", &ele);

	printf("Enter the number of rows : ");
	scanf("%d", &rows);

	// while statement prints a loop of the multiplication table.

	while (i <= rows)
	{
		product = ele * i;
		printf("%d X %d = %d\n", ele, i, product);
		i += 1;
	}
}