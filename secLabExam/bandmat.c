#include <stdio.h>

int maxi(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}

int mini(int a, int b) {
	if (a<b) {
		return a;
	}
	else {
		return b;
	}
}

int bandk(int N, int arr[][N], int k) {
	int ret=0;
	for (int i=0; i<N; i++) {
		int m1, m2;

		if (i-k >=0) {
			m1 = maxi(arr[i][0], arr[i][i-k]);
		}
		else {
			m1 = arr[i][0];
		}

		if (i+k < N-1) {
			m2 = mini(arr[i][i+k], arr[i][N-1]);
		}
		else {
			m2 = arr[i][N-1];
		}
		
		for (int j=0; j<N; j++) {
			if ((m1 <= arr[i][j]) && (arr[i][j] <= m2)) {
				ret = 1;
				break;
			}
		}

		if (ret==1) {
			break;
		}
	}
	
	return ret;
}

int main(void) {
	int N, Q, temp;

	scanf("%d", &N);

	int matrix[N][N];

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	scanf("%d", &Q);

	int ans[Q];

	for (int i=0; i<Q; i++) {
		scanf("%d", &temp);
		ans[i] = bank(N, matrix, temp);
	}

	for (int i=0; i<Q; i++) {
		if (ans[i] == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}