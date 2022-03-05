#include <stdio.h>

#define MOD 1000000007

int multmod(int a, int b) {
	long num1, num2, temp, multdiff=1;
	int result;
	num1 = (long) a;
	num2 = (long) b;
	temp = num1* num2;

	while (multdiff*MOD < temp) {
		multdiff++;
	}
	temp -= MOD*(multdiff-1);

	result = (int) temp;
	return temp;
}

int main(void) {
	int M, N, Q, result=1;
	long temp=1;
	scanf("%d", &N);
	scanf("%d", &M);
	int numarray[N][M];
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d", &numarray[i][j]);
		}
	}
	scanf("%d", &Q);
	int query[Q][4], ans[Q];
	for (int i=0;i<Q;i++) {
		for (int j=0;j<4;j++) {
			scanf("%d", &query[i][j]);
		}
	}

	// Assuming 0<=x<=N, 0<=y<=M.
	for (int i=0; i<Q;i++) {
		for (int j=query[i][0]; j<=query[i][2];j++) {
			for (int k = query[i][1]; k<= query[i][3]; k++) {
				//result = multmod(result, numarray[j][k]);

				temp =(long) result*numarray[j][k];
				temp = temp % MOD;
				result = (int) temp;
			}
			// multiply(using modulo)
			// Verify is it M X N or vice versa.
		}
		ans[i] = result;
		result = 1;
	}

	for (int i=0;i<Q;i++) {
		printf("%d\n", ans[i]);
	}
	// Need to optimize further. Try using long? for first 3 nums, then use multmod(10^18 < LONG_MAX < 10^19).
}