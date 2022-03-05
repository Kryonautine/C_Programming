#include <stdio.h>

int maxi(int a, int b) {
	if ( a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int housecalc(int N, int H[], int M, int* l) {
	int lds[N], no=0, max=0;

	for (int i=0; i< N; i++) {
		lds[i] = 1;
	}

	for (int i =1; i<N;i++) {
		for (int j=0;j<i;j++) {
			if ((H[i] < H[j]) && (lds[i] <= lds[j] + 1)) { // Remove = in H[i] < H[j]
				for (int k = j+1;k<i;k++) {
					if (H[k] >= H[j]) {
						no++;
						break;
					}
				}
				if (no==0) {
					lds[i] = lds[j] +1;
				}
				else {
					no=0;
				}
			}
		}
	}

	if (M != -1) {
		*l = lds[M-1];
	}

	for (int i=0;i<N;i++) {
		if (max <= lds[i]) {
			max = lds[i];
		}
	}

	return max;
}

int main(void) {
	int N, M, tot1, tot2, tot, a=1, b=-1, ldsm=1;

	scanf("%d", &N);
	scanf("%d", &M);

	int H[M], Hnot[N-M];

	for (int i = 0; i<N; i++) {
		if (i<M) {
			scanf("%d", &H[i]);
		}
		else {
			scanf("%d", &Hnot[i-M]);
		}
	}

	tot1 = housecalc(M, H, M, &ldsm);
	tot2 = housecalc(N-M, Hnot, b, &a);

	tot = maxi(tot1, tot2 + ldsm);
	// Segfault ??

	printf("%d", tot);
}