#include <stdio.h>

int main(void) {
	long kunal=0, success=0, kunwar=0, N, K;
	
	scanf("%ld", &N);
	scanf("%ld", &K);

	long A[N];
	for (int i = 0; i< N; i++) {
		scanf("%ld", &A[i]);
	}

	if (K > N*8) {
		printf("-1\n");
	}
	else {
		for (int i = 0; i < N; i++) {

			// Can move array here and use it as an element to reduce memory consumption.

			kunwar += A[i];

			if (kunwar > 8) {
				kunal += 8;
				kunwar -= 8;
			}
			else {
				kunal += kunwar;
				kunwar = 0;
			}

			if (kunal >= K) {
				success = 1;
				printf("%d", i+1);
				break;
			}
		}

		if (success == 0) {
			printf("-1\n");
		}
	}
}