#include <stdio.h>

void main()
{

	int x1, x2, y1, y2, z1, z2, dotProduct;

	printf("Enter the x- component of 1st vector : ");
	scanf("%d", &x1);
	printf("Enter the y- component of 1st vector : ");
	scanf("%d", &y1);
	printf("Enter the z- component of 1st vector : ");
	scanf("%d", &z1);

	printf("Enter the x- component of 2nd vector : ");
	scanf("%d", &x2);
	printf("Enter the y- component of 2nd vector : ");
	scanf("%d", &y2);
	printf("Enter the z- component of 2nd vector : ");
	scanf("%d", &z2);

	dotProduct = x1*x2 + y1*y2 + z1*z2;

	printf("The dot product of vectors (%d,%d,%d) and (%d,%d,%d) is : %d\n", x1, y1, z1, x2, y2, z2, dotProduct);

}