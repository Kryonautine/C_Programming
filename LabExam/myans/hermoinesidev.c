#include <stdio.h>

int main(void) {
	int numtest, j=0;
	scanf("%d", &numtest);

	int karr[numtest], wo=0, we=0;
	char omess[numtest][100000], emess[numtest][100000];
	char *optr, *eptr;

	for (int i=0; i<numtest+1;i++) {
		scanf("%d", karr[i-1]);
		fgets(omess[i-1], 100000, stdin);
		fgets(emess[i-1], 100000, stdin);
		while (*optr != "\n") {
			if (omess[i][j] == " ") {
				optr++;
				wo++;
			}
		}
	}
}