#include <stdio.h>

int main(void) {
	int N, herm=1, circ=1, mod;

	scanf("%d", &N);

	int matrixr[N][N], matrixc[N][N], transr[N][N], transc[N][N];

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			scanf("%d", &matrixr[i][j]);
			transr[j][i] = matrixr[i][j];
			scanf("%d", &matrixc[i][j]);
			transc[j][i] = -(matrixc[i][j]);
		}
	}

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			if ((transr[i][j] != matrixr[i][j]) || (transc[i][j] != matrixc[i][j])) {
				herm=0;
			}
		}
		if (herm == 0) {
			break;
		}
	}

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			mod = (j+i) % N;
			if ((matrixr[0][j] != matrixr[i][mod]) || (matrixc[0][j] != matrixc[i][mod])) {
				circ=0;
			}
		}
		if (circ == 0) {
			break;
		}
	}

	if ((herm==1) && (circ == 1)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}