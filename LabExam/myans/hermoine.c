#include <stdio.h>

int main(void) {
	int numtest;
	scanf("%d", &numtest);

	int karr[numtest];
	char omess[numtest][100000], emess[numtest][100000];
	char ele;

	for (int i=0; i<numtest+1;i++) {
		scanf("%d", karr[i-1]);
		fgets(omess[i-1], 100000, stdin);
		fgets(emess[i-1], 100000, stdin);
		while (ele != "\n") {
			if (ele == " ") {
				continue;
			}
			

		}
	}
}