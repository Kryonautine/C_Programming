#include <stdio.h>

int housecalc(int N, int H[], int check) {
	int lds[N], max=0;

	for (int i=0; i< N; i++) {
		lds[i] = 1;
	}

	for (int i =1; i<N;i++) {
		for (int j=0;j<i;j++) {
			if ((H[i] < H[j]) && (lds[i] <= lds[j] + 1)) { // Remove = in H[i] < H[j]
				lds[i] = lds[j] +1;
			}
		}
	}

	for (int i=0;i<N;i++) {
		if (max <= lds[i]) {
			max = lds[i];
		}
	}
	
	if (check == 0) {
		return max;
	}
	else {
		return lds[N-1];
	}
}

int main(void) {
	int N, M, totm, totn, tot, sale;

	scanf("%d", &N);
	scanf("%d", &M);

	int H[N], H1[M], H2[N-M];

	for (int i = 0; i<N; i++) {
		scanf("%d", &H[i]);
		if (i<M) {
			H1[i]= H[i];
		}
		else {
			H2[i-M]= H[i];
		}
	}

	totm = housecalc(M, H1, 1);
	totn = housecalc(N-M, H2, 0);
	tot = housecalc(N, H, 0);

	totm += totn;

	if (tot > totm) {
		sale = tot;
	}
	else {
		sale = totm;
	}

	printf("%d", sale);
}