#include <stdio.h>

int main(void) {
	int M, N;

	scanf("%d", &M);
	scanf("%d", &N);

	long int matrix1[M][N];

	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++) {
			scanf("%ld", &matrix1[i][j]);
		}
	}

	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++) {
			printf("%ld ", matrix1[i][j]);
		}
		printf("\n");
	}
}