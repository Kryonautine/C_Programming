#include <stdio.h>
#include <math.h>

// Modify this to reduce number of iterations.
#define MAX_BIN_LEN 60

void binrep(char str[], long long num) {

	if (num > 1) {
		binrep(num/2);
	}

	printf("%d", num % 2);
}

int main(void) {
	long long N, K;

	scanf("%lld", &N);

	long long A[N], pow2[N];
	char bin[N][MAX_BIN_LEN];

	for (long long i=0; i<N; i++) {
		scanf("%lld", &A[i]);
	}

	for (long long i=0; i<N; i++) {
		binrep(&bin[i][0], A[i]);
	}

	scanf("%lld", &K);

	for (long long i=0; i<N; i++) {
		printf("%s\n", &bin[i][0]);
	}
}