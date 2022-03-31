#include <stdio.h>

int main(void) {
	int N, K, max=0;

	scanf("%d", &N);
	scanf("%d", &K);

	char ham[N][K+1];

	for (int i=0; i<N; i++) {
		scanf("%s", &ham[i][0]);
	}

	printf("\n");
	printf("=======\n");
	printf("\n");

	for (int i=0; i<N; i++) {
		for (int j=i; j<N-1; j++) {
			int tes=0;
			for (int m=0; m<K; m++) {
				if (ham[j][m] != ham[j+1][m]) {
					tes++;
				}
			}
			if (tes > max) {
				max = tes;
			}
		}
	}

	for (int i=0; i<N; i++) {
		printf("%s\n", ham[i]);
	}

	printf("%d\n", max);
}