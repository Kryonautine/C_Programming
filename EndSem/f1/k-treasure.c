#include <stdio.h>

// Modify this to reduce number of iterations.
#define MAX_BIN_LEN 70

long long power(long long x, long long y) {
	long long ret=x;

	if ((y==0) ||(y==1)) {
		if (y==1) {
			return x;
		}
		else {
			return 1;
		}
	}
	else {
		for (long long i=2; i<=y ;i++) {
			ret *= x;
		}
		return ret;
	}
}

void binrep(char str[], long long num) {

	for (long long i=MAX_BIN_LEN-1; i >=0; i++) {
		long long temp = power(2, i);
		if (num >= temp) {
			str[MAX_BIN_LEN-i] = '1';
			num -= temp;
		}
		else {
			str[MAX_BIN_LEN-i] = '0';
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
		printf("%s", &bin[i][0]);
	}
}