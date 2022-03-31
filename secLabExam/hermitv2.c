#include <stdio.h>

int main(void) {
	long long N, M, herm1=1, herm2=1;

	scanf("%lld", &N);
	scanf("%lld", &M);

	long long mat1r[N][M], mat1c[N][M], trans1r[N][M], trans1c[N][M];
	long long mat2r[N][M], mat2c[N][M], trans2r[N][M], trans2c[N][M];

	for (long long i=0;i<N;i++) {
		for (long long j=0;j<M;j++) {
			scanf("%lld", &mat1r[i][j]);
			trans1r[j][i] = mat1r[i][j];
			scanf("%lld", &mat1c[i][j]);
			trans1c[j][i] = -(mat1c[i][j]);
		}
	}

	for (long long i=0;i<N;i++) {
		for (long long j=0;j<M;j++) {
			scanf("%lld", &mat2r[i][j]);
			trans2r[j][i] = mat2r[i][j];
			scanf("%lld", &mat2c[i][j]);
			trans2c[j][i] = -(mat2c[i][j]);
		}
	}

	for (long long i=0;i<N;i++) {
		for (long long j=0;j<M;j++) {
			if ((trans1r[i][j] != mat1r[i][j]) || (trans1c[i][j] != mat1c[i][j])) {
				herm1=0;
			}
		}
		if (herm1 == 0) {
			break;
		}
	}

	for (long long i=0;i<N;i++) {
		for (long long j=0;j<M;j++) {
			if ((trans2r[i][j] != mat2r[i][j]) || (trans2c[i][j] != mat2c[i][j])) {
				herm2=0;
			}
		}
		if (herm2 == 0) {
			break;
		}
	}

	if ((herm2==1) && (herm1==1)) {
		for (long long i=0;i<N;i++) {
			for (long long j=0;j<M;j++) {
				mat2r[i][j] += mat1r[i][j];
				mat2c[i][j] += mat1c[i][j];
				printf("%lld ", mat2r[i][j]);
				printf("%lld ", mat2c[i][j]);
			}
			printf("\n");
		}
	}
	else {
		long long k;
		if (N>M) {
			k=M;
		}
		else {
			k=N;
		}
		
		for (long long i=0; i<k;i++) {
			for (long long j=0; j<k;j++) {
				if (j == k-1) {
					if (i==j) {
						printf("1 ");
						printf("0\n");
					}
					else {
						printf("0 ");
						printf("0\n");
					}
				}
				else {
					if (i==j) {
						printf("1 ");
						printf("0 ");
					}
					else {
						printf("0 ");
						printf("0 ");
					}
				}
			}
		}
	}
}