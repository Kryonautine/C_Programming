#include <stdio.h>

int main(void) {
	int L, K, m, esc=0;
	scanf("%d", &L);
	scanf("%d", &K);
	scanf("%d", &m);

	char dna[L];
	scanf("%s", dna);

	for (int i = 0; i<L; i += (K-m)) {
		for (int j = i; j< i+K; j++) {
			printf("%c", dna[j]);
			if (j == L-1) {
				esc++;
				break;
			}
		}
		printf("\n");
		if (esc != 0) {
			break;
		}
	}

	// Use qsort
	// Split into [L/K] kmers of size K + {K}*K kmer.
	// Figure out what m is supposed to do.
	// Figure out why test 1 failed and maybe write actual code with a flowchart.
}