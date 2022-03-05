#include <stdio.h>

int maximum(int a, int b) {
	if ( a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int housecalc(int N, int H[], int M ) {
	int max = H[0], sec=0;

	for (int i = 0; i< N; i++) {
		if (H[i] >= max) {
			max = H[i];
			sec++;
		}
	}

	int part[sec];

	int j=0;
	max = 0;
	for (int i = 0; i< N; i++) {
		if (H[i] >= max) {
			max = H[i];
			part[j] = i;
			j++;
		}
	}

	for (int i = 0; i< sec; i++) {
		printf("%d ", part[i]);
	}
	
	//
	if (sec == 1)
	//

	printf("\n");

	// Add base case, split and recursively call all sections.

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