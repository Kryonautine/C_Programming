#include <stdio.h>

typedef struct strArray
{
	int K;
	int char[K];
}

int main(void) {
	int N, K;

	scanf("%d", &N);
	scanf("%d", &K);

	strArray ham[N];

	for (int i=0; i<N; i++) {
		scanf("%s", &ham[i]);
	}

	printf("\n");
	printf("=======\n");
	printf("\n");
	for (int i=0; i<N; i++) {
		printf("%s\n", &ham[i]);
	}
}