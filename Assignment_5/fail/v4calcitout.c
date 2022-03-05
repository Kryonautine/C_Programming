#include <stdio.h>

#define MOD 1000000007

void preProcess(int N, int M, int A[][], int aux[][]) {

	for (int i=0; i<M; i++)
		aux[0][i] = A[0][i];
	
	for (int i=1; i<N; i++) {
		for (int j=0;j<M;j++){
			aux[i][j] = (A[i][j] * aux[i-1][j]) % MOD;
		}
	}

	for (int i=1; i<N; i++) {
		for (int j=0;j<M;j++){
			aux[i][j] = (aux[i][j] * aux[i][j-1]) % MOD;
		}
	}
}

// Using modular division (altenate maybe modulus inverse)
int ansQuery(int N, int M, int aux[][], int x1, int y1, int x2, int y2) {

	int res = aux[x2][y2];

	res = (res/aux[x1-1][y1]) % MOD;
	res = (res/aux[x1][y1-1]) % MOD;
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
		ans[i] = ansQuery(N, M, aux, Q[i][0], Q[i][1], Q[i][2], Q[i][3]);
	}

	for (int i=0;i<Q;i++) {
		printf("%d\n", ans[i]);
	}
	// Need to optimize further. Try using long? for first 3 nums, then use multmod(10^18 < LONG_MAX < 10^19).
	// Binary Search, -precomputation on matrix-, multiplicative modulo inverse, binary exponentiation, Extended Euclidean Algorithm.
}