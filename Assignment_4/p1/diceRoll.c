#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX 2147483647

int main(void) {
	srand(1001);
	int x, dice[6];
	
	for(int i=0;i<6;i++) {
		dice[i] = 0;
	}

	for (int i=0;i<1000000;i++) {
		x = (int) (6*((double)rand()/RAND_MAX)+1);

		// Comparing the value of the random num with the faces.
		for (int j=0;j<6;j++) {
			if (x==j+1) {
				dice[j]++;
				break;
			}
			if (x==7) {
				i--;
			}
		}
	}

	for(int i=0;i<6;i++) {
		printf("face %d has appeared %d times.\n", i+1, dice[i]);
	}
}
// Still need to check how far away it is from uniform distribution.