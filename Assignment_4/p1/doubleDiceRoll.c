#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 2147483647

int main(void) {
	srand(998);
	int x, y, dice[11];
	
	for(int i=0;i<11;i++) {
		dice[i] = 0;
	}

	for (int i=0;i<1000000;i++) {
		x = (int) (6*((double)rand()/RAND_MAX)+1);
		y = (int) (6*((double)rand()/RAND_MAX)+1);

		// Comparing the value of the random num with the faces.
		for (int j=0;j<11;j++) {
			if ((x==7) || (y==7)) {
				i--;
				continue;
			}
			if (x+y==j+2) {
				dice[j]++;
				break;
			}
		}
	}

	for(int i=0;i<11;i++) {
		printf("sum %d has appeared %d times.\n", i+2, dice[i]);
	}
}
// Still need to check how far away it is from uniform distribution.