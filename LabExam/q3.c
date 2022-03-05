#include <stdio.h>

int main(void) {
	int N, Q;
	scanf("%d", &N);

	int cho[N];
	for (int i=0;i<N;i++) {
		scanf("%d", &cho[i]);
	}

	scanf("%d", &Q);

	int l[Q], r[Q], ans[Q];
	for (int i=0;i<Q;i++) {
		ans[i] = 0;
		scanf("%d", &l[i]);
		scanf("%d", &r[i]);

		for (int j=0; j<N;j++) {
			if (cho[j] <= r[i]) {
				if (cho[j] >= l[i]) {
					ans[i]++;
				}
			}
		}
	}
	
	for (int i=0; i<Q;i++) {
		printf("%d ", ans[i]);
	}
}