#include <stdio.h>

void main()
{

	int ele, product, i = 1, rows;
	
	printf("Enter the number : ");
	scanf("%d", &ele);
	
	printf("Enter the number of rows : ");
	scanf("%d", &rows);

loop:

	// loop is a label to execute goto statement.

	product = ele * i;
	printf("%d X %d = %d\n", ele, i, product);
	i += 1;

	if (i <= rows)

		goto loop;
}