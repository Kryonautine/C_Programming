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

	if (g != 1) {
		for (long long i=1; i< MOD; i++) {
			if (((a % MOD) * (i % MOD)) % MOD == 1)
				res = i;
		}
	}
	else {
		res = (x % MOD + MOD) % MOD;
	}
	return res;
}

void preProcess(long long N, long long M, long long A[][M], long long aux[][M]) {

	int t1=0, t2 = 0, t3 =0;

	for (long long i=0; i<M; i++) {
		aux[0][i] = A[0][i];
		t1 =A[0][i];
	}
	
	for (long long i=1; i<N; i++) {
		for (long long j=0;j<M;j++){
			aux[i][j] = (A[i][j] * aux[i-1][j]) % MOD;
			t1 = A[i][j];
			t2 = aux[i][j];
			t3 = aux[i-1][j];
			// printf("A[%d][%d] = %d\n", i, j, A[i][j]);
			// printf("aux[%d][%d] = %d\n", i, j, aux[i][j]);
		}
	}

	// Problem lies here.
	for (long long i=1; i<N; i++) {
		for (long long j=1;j<M;j++){
			t1 = aux[i][j];
			aux[i][j] = (aux[i][j] * aux[i][j-1]) % MOD;
			t2 = aux[i][j];
			t3 = aux[i][j-1];
		}
	}
	// Problem lies here.
}

// Using modular division (altenate maybe modulus inverse)
// Modular division has failed, replace division with multiplication by mod inverses.
long long ansQuery(long long N, long long M, long long aux[][M], long long x1, long long y1, long long x2, long long y2) {

	long long res = aux[x2][y2];

	if ((x1 > 0) && (y1 > 0))
		res = (res * aux[x1-1][y1-1]) % MOD;
	if (x1 > 0)
		res = (res * modinv(aux[x1-1][y1])) % MOD;
	if (y1 > 0)
		res = (res * modinv(aux[x1][y1-1])) % MOD;

	return res;
}

// Overflow?
long long main(void) {
	long long M, N, Q;
	long result=1;
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