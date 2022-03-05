#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void * b) {
	return ( *(int*)a - *(int*)b);
}

int main(void) {

	int n;

	scanf("%d", &n);

	int A[n];

	for (int i=0;i<n;i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, n, sizeof(int), cmpfunc);

	for (int i=0;i<n;i++) {
		printf("%d ", A[i]);
	}
}