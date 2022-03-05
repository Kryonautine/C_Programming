#include <stdio.h>

#define MOD 1000000007

int gcd(int a, int m, int *x, int *y) {

	if (a==0) {
		*x = 0, *y =1;
		return m;
	}

	int x1, y1;
	int g = gcd(m % a, a, &x1, &y1);

	*x = y1 - (m/a) * x1;
	*y = x1;

	return g;
}

int modinv(int a) {

	int x, y, res, g;

	g = gcd(a, MOD, &x, &y);

	if (g != 1) {
		for (int i=1; i< MOD; i++) {
			if (((a % MOD) * (i % MOD)) % MOD == 1)
				res = i;
		}
	}
	else {
		res = (x % MOD + MOD) % MOD;
	}
	return res;
}

void preProcess(int N, int M, int A[][M], int aux[][M]) {

	for (int i=0; i<M; i++)
		aux[0][i] = A[0][i];
	
	for (int i=1; i<N; i++) {
		for (int j=0;j<M;j++){
			aux[i][j] = (A[i][j] * aux[i-1][j]) % MOD;
			// printf("A[%d][%d] = %d\n", i, j, A[i][j]);
			// printf("aux[%d][%d] = %d\n", i, j, aux[i][j]);
		}
	}

	for (int i=1; i<N; i++) {
		for (int j=0;j<M;j++){
			aux[i][j] = (aux[i][j] * aux[i][j-1]) % MOD;
		}
	}
}

// Using modular division (altenate maybe modulus inverse)
// Modular division has failed, replace division with multiplication by mod inverses.
int ansQuery(int N, int M, int aux[][M], int x1, int y1, int x2, int y2) {

	int res = aux[x2][y2];

	if (x1 > 0)
		res = (res * modinv(aux[x1-1][y1])) % MOD;
	if (y1 > 0)
		res = (res * modinv(aux[x1][y1-1])) % MOD;
	if ((x1 > 0) && (y1 > 0))
		res = (res * aux[x1-1][y1-1]) % MOD;

	return res;
}

int main(void) {
	int M, N, Q;
	long result=1;
	scanf("%d", &N);
	scanf("%d", &M);

	int numarray[N][M], aux[N][M];
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d", &numarray[i][j]);
			numarray[i][j] = numarray[i][j] % MOD;
		}
	}

	preProcess(N, M, numarray, aux);

	scanf("%d", &Q);
	int query[Q][4], ans[Q];
	for (int i=0;i<Q;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d", &query[i][j]);
		}
		ans[i] = ansQuery(N, M, aux, query[i][0], query[i][1], query[i][2], query[i][3]);
	}

	for (int i=0;i<Q;i++) {
		printf("%d\n", ans[i]);
	}
	// Need to optimize further. Try using long? for first 3 nums, then use multmod(10^18 < LONG_MAX < 10^19).
	// Binary Search, -precomputation on matrix-, multiplicative modulo inverse, binary exponentiation, Extended Euclidean Algorithm.
}