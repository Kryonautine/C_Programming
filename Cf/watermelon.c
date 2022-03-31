#include <stdio.h>

int main(void) {
	int w;

	scanf("%d", &w);

	if (w % 2 == 1) {
		printf("NO");
	}
	else {
		if (w > 2) {
			printf("YES");
		}
		else {
			printf("NO");
		}
	}
}