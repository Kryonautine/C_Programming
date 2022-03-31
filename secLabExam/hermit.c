#include <stdio.h>

int main(void) {
	int N, M, herm1=1, herm2=1;

	scanf("%d", &N);
	scanf("%d", &M);

	int mat1r[N][M], mat1c[N][M], trans1r[N][M], trans1c[N][M];
	int mat2r[N][M], mat2c[N][M], trans2r[N][M], trans2c[N][M];

	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d", &mat1r[i][j]);
			trans1r[j][i] = mat1r[i][j];
			scanf("%d", &mat1c[i][j]);
			trans1c[j][i] = -(mat1c[i][j]);
		}
	}

	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d", &mat2r[i][j]);
			trans2r[j][i] = mat2r[i][j];
			scanf("%d", &mat2c[i][j]);
			trans2c[j][i] = -(mat2c[i][j]);
		}
	}

	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if ((trans1r[i][j] != mat1r[i][j]) || (trans1c[i][j] != mat1c[i][j])) {
				herm1=0;
			}
		}
		if (herm1 == 0) {
			break;
		}
	}

	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if ((trans2r[i][j] != mat2r[i][j]) || (trans2c[i][j] != mat2c[i][j])) {
				herm2=0;
			}
		}
		if (herm2 == 0) {
			break;
		}
	}

	if ((herm2==1) && (herm1==1)) {
		for (int i=0;i<N;i++) {
			for (int j=0;j<M;j++) {
				mat2r[i][j] += mat1r[i][j];
				mat2c[i][j] += mat1c[i][j];
				printf("%d ", mat2r[i][j]);
				printf("%d ", mat2c[i][j]);
			}
			printf("\n");
		}
	}
	else {
		int k;
		if (N>M) {
			k=M;
		}
		else {
			k=N;
		}
		
		for (int i=0; i<k;i++) {
			for (int j=0; j<k;j++) {
				if (i==j) {
					printf("1 ");
				}
				else {
					printf("0 ");
				}
			}
			printf("\n");
		}
	}
}