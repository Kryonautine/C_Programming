#include <stdio.h>

int main(void) {
	int M, N, i=0, j=0;

	scanf("%d", &M);
	scanf("%d", &N);

	long int matrix1[M][N], matrix2[M][N], temp;

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%ld", &temp);
			matrix1[i][j] = temp;
		}
	}

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%ld", &temp);
			matrix2[i][j] = temp;
		}
	}

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			matrix2[i][j] += matrix1[i][j];
			printf("%ld ", matrix2[i][j]);
		}
		printf("\n");
	}
}