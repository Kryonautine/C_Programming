#include <stdio.h>

int main(void) {
	int M, N, Y, i=0, j=0, k=0;

	scanf("%d", &M);
	scanf("%d", &N);
	scanf("%d", &Y);

	long int matrix1[M][N], matrix2[N][Y], matrixf[M][Y], temp;

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%ld", &matrix1[i][j]);
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<Y;j++) {
			scanf("%ld", &matrix2[i][j]);
		}
	}

	for (k=0;k<Y;k++) {
		for (i=0;i<M;i++) {
			temp=0;
			for (j=0;j<N;j++) {
				temp += matrix1[i][j]*matrix2[j][k];
			}
			matrixf[i][k] = temp;
		}
	}

	for (i=0;i<M;i++) {
		for (j=0;j<Y;j++) {
			printf("%ld ", matrixf[i][j]);
		}
		printf("\n");
	}
}