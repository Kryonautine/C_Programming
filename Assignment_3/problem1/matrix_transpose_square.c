#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int matdim, i=0, j=0;

	scanf("%d", &matdim);

	int matrix[matdim][matdim];

	for (i=0;i<matdim;i++) {
		for (j=0;j<matdim;j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	for (i=1;i<matdim;i++) {
		for (j=0;j<i;j++) {
			swap(&matrix[i][j], &matrix[j][i]);
		}
	}

	for (i=0;i<matdim;i++) {
		for (j=0;j<matdim;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}