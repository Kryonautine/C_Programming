#include <stdio.h>

int main(void) {
	int proom[9], i=0, j=0, k=0, numP[9];

	int hotel[100][30];

	for (i=0;i<100;i++) {
		for (j=0;j<30;j++) {
			scanf("%d", &hotel[i][j]);
		}
	}

	k=0;
	for (i=0;i<9;i++) {
		proom[i] = k;
		k++;
		numP[i] = 0;
	}

	for (k=0;k<9;k++) {
		for (i=0;i<100;i++) {
			for (j=0;j<30;j++) {
				if (proom[k] == hotel[i][j])
					numP[k]++;
			}
		}
	}

	for (i=0;i<9;i++) {
		printf("%d\n", numP[i]);
	}
}