#include <stdio.h>

int main(void) {
	int M, N, i=0, j=0, temp;

	scanf("%d", &M);
	scanf("%d", &N);

	int matrix[N][M];

	for (i=0;i<M;i++) {
		for (j=0;j<N;j++) {
			scanf("%d", &temp);
			matrix[j][i] = temp;
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<M;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}