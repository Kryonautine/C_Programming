#include <stdio.h>
#include <math.h>

// Modify this to reduce number of iterations.
#define MAX_BIN_LEN 60

void binrep(char str[], long long num) {

	for (long long i=MAX_BIN_LEN-1; i >=0; i--) {
		long long temp = pow(2, i);
		if (num >= temp) {
			str[MAX_BIN_LEN-i] = '1';
			num -= temp;
			// printf("%lld\n", MAX_BIN_LEN-i);
		}
		else {
			str[MAX_BIN_LEN-i] = '0';
			// printf("%lld\n", MAX_BIN_LEN-i);
		}
	}
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