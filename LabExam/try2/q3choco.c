#include <stdio.h>

// Sorts array in ascending order(bubblesort)
void arrSort(int N, int c[]) {
	int check=-1;

	while (check != N-1) {
		check=0;
		for (int i=0; i < N-1; i++) {
			if (c[i] > c[i+1]) {
				int temp;
				temp = c[i];
				c[i] =c[i+1];
				c[i+1] = temp;
			}
			else {
				check++;
			}
		}
	}
}

int main(void) {
	int N, Q, l, r;
	
	scanf("%d", &N);

	int c[N];

	for (int i=0; i<N; i++) {
		scanf("%d", &c[i]);
	}

	arrSort(N, c);

	scanf("%d", &Q);

	int ans[Q];

	for (int i=0; i< Q; i++) {
		int a = N, b=-1;

		scanf("%d", &l);
		scanf("%d", &r);

		// Use binary search instead.
		for (int j=0; j<N; j++) {
			if (c[j] >= l) {
				a = j+1;
				break;
			}
		}

		for (int j=0; j<N; j++) {
			if (c[N-j-1] <= r) {
				b = N-j;
				break;
			}
		}

		ans[i] = b-a+1;
		if (ans[i] < 0) {
			ans[i] =0;
		}
	}

	for (int i=0; i<Q; i++) {
		printf("%d ", ans[i]);
	}
}