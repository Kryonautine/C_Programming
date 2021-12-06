#include <stdio.h>

void main()
{
	int a;
	
	printf("Enter the number:");
	scanf("%d",&a);

	if (a>=0)
	{
		printf("|%d|=|%d|\n",a,a);
	}
	else
	{
		printf("|%d|=|%d|\n",a,-a);
	}

	//	printf("|%d|=|%d|\n",a, a>=0?a:-a);
}