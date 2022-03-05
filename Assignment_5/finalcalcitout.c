#include <stdio.h>

#define MOD 1000000007

long long gcd(long long a, long long m, long long *x, long long *y) {

	if (a==0) {
		*x = 0, *y =1;
		return m;
	}

	long long x1, y1;
	long long g = gcd(m % a, a, &x1, &y1);

	*x = y1 - (m/a) * x1;
	*y = x1;

	return g;
}

long long modinv(long long a) {

	long long x, y, res, g;

	g = gcd(a, MOD, &x, &y);

	res = (x % MOD + MOD) % MOD;

	return res;
}

void preProcess(long long N, long long M, long long A[][M], long long aux[][M]) {

	for (long long i=0; i<M; i++) {
		aux[0][i] = A[0][i];
	}
	
	for (long long i=1; i<N; i++) {
		for (long long j=0;j<M;j++){
			aux[i][j] = (A[i][j] * aux[i-1][j]) % MOD;
		}
	}

	for (long long i=0; i<N; i++) {
		for (long long j=1;j<M;j++){
			aux[i][j] = (aux[i][j] * aux[i][j-1]) % MOD;
		}
	}
}

long long ansQuery(long long N, long long M, long long aux[][M], long long x1, long long y1, long long x2, long long y2) {

	long long res = aux[x2][y2];
	long long inv;

	if ((x1 > 0) && (y1 > 0)) {
		res = (res * aux[x1-1][y1-1]) % MOD;
	}
	if (x1 > 0) {
		inv = modinv(aux[x1-1][y2]);
		res = (res * inv) % MOD;
	}
	if (y1 > 0) {
		inv = modinv(aux[x2][y1-1]);
		res = (res * inv) % MOD;
	}

	return res;
}

int main(void) {
	long long M, N, Q;
	scanf("%lld", &N);
	scanf("%lld", &M);

	long long numarray[N][M], aux[N][M];
	for (long long i=0;i<N;i++) {
		for (long long j=0;j<M;j++) {
			scanf("%lld", &numarray[i][j]);
			numarray[i][j] = numarray[i][j] % MOD;
		}
	}

	preProcess(N, M, numarray, aux);

	scanf("%lld", &Q);
	long long query[Q][4], ans[Q];
	for (long long i=0;i<Q;i++) {
		for (long long j=0;j<4;j++) {
			scanf("%lld", &query[i][j]);
		}
		ans[i] = ansQuery(N, M, aux, query[i][0], query[i][1], query[i][2], query[i][3]);
	}

	for (long long i=0;i<Q;i++) {
		printf("%lld\n", ans[i]);
	}
	// Need to optimize further. Try using long? for first 3 nums, then use multmod(10^18 < LONG_MAX < 10^19).
	// Binary Search, -precomputation on matrix-, multiplicative modulo inverse, binary exponentiation, Extended Euclidean Algorithm.
}