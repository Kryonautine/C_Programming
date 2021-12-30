#include <stdio.h>

int main(void)
{

	int ele, product, i = 1, rows;
	
	scanf("%d", &ele);
	
	scanf("%d", &rows);

loop:

	// loop is a label to execute goto statement.

	product = ele * i;
	printf("%d\n", product);
	i += 1;

	if (i <= rows)

		goto loop;
}