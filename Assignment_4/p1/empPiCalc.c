#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 2147483647

int main(void) {
	srand(249);
	int num, ins=0;
	double x, y, piEstim=0;

	printf("Enter number of points :");
	scanf("%d", &num);

	for (int i=0;i<num;i++) {
		x =(double) (2.0*((double) rand()/RAND_MAX))-1;
		y =(double) (2.0*((double) rand()/RAND_MAX))-1;

		if (x*x + y*y <= 1) {
			ins++;
		}
	}

	piEstim =(double) 4.0*((double) ins/num);
	printf("Pi Estimate = %f", piEstim);
}