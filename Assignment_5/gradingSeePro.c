#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

int main(void) {

	int n, m, x=0, y=0, equal =0;

	scanf("%d", &n);
	scanf("%d", &m);

	int A[n], B[m];

	for (int i=0;i<n;i++) {
		scanf("%d", &A[i]);
	}

	for (int i=0;i<m;i++) {
		scanf("%d", &B[i]);
	}

	qsort(A, n, sizeof(int), cmpfunc);
	qsort(B, m, sizeof(int), cmpfunc);

	while (1) {
		if ((x >= n) || (y >= m)) {
			break;
		}

		if (A[x] > B[y]) {
			y++;
		}
		else {
			if (A[x] == B[y]) {
				equal++;
				x++;
			}
			else {
				x++;
			}
		}
	}

	printf("%d", equal);
}