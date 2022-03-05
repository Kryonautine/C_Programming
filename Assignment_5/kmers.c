#include <stdio.h>

int main(void) {
	int L, K, m;
	scanf("%d", &L);
	scanf("%d", &K);
	scanf("%d", &m);

	char dna[L];
	scanf("%s", dna);

	for (int i = 0; i<L; i += (K-m)) {
		for (int j = i; j< i+K; j++) {
			if (dna[j] == '\0') {
				break;
			}
			printf("%c", dna[j]);
		}
		if (i+K > L) {
			break;
		}
		if (i+1 == L) {
			break;
		}
		printf("\n");
	}

}