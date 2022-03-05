#include <stdio.h>

int housecalc(int N, int H[],int M) {
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

	for (int i=0;i<N;i++) {
		if (max <= lds[i]) {
			max = lds[i];
		}
	}

	// Reconstruct all possible paths.

	return max;
}

int main(void) {
	int N, M, tot;

	scanf("%d", &N);
	scanf("%d", &M);

	int H[N];

	for (int i = 0; i<N; i++) {
		scanf("%d", &H[i]);
	}

	tot = housecalc(N, H, M);

	printf("tot = %d", tot);
}