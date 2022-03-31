#include <stdio.h>

int main(void) {
	int N, Q;
	scanf("%d", &N);

	int cho[N];
	for (int i=0;i<N;i++) {
		scanf("%d", &cho[i]);
	}

	scanf("%d", &Q);

	int l, r, ans[Q];
	for (int i=0;i<Q;i++) {
		ans[i] = 0;
		scanf("%d", &l);
		scanf("%d", &r);

		for (int j=0; j<N;j++) {
			if (cho[j] <= r) {
				if (cho[j] >= l) {
					ans[i]++;
				}
			}
		}
	}
	
	for (int i=0; i<Q;i++) {
		printf("%d ", ans[i]);
	}
}