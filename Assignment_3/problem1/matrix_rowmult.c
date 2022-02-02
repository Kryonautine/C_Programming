#include <stdio.h>

int main(void) {
	int M, N, i=0, j=0;

	scanf("%d", &M);
	scanf("%d", &N);

	long int matrix1[M][N], matrix2[N], matrixf[M], temp;

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%ld", &matrix1[i][j]);
		}
	}

	for (i=0;i<N;i++) {
		scanf("%ld", &matrix2[i]);
	}

	for (i=0;i<M;i++) {
		temp=0;
		for (j=0;j<N;j++) {
			temp += matrix1[i][j]*matrix2[j];
		}
		matrixf[i] = temp;
		printf("%ld\n", matrixf[i]);
	}
}