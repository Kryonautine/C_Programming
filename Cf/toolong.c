#include <stdio.h>
#include <string.h>

int main(void) {
	int num;

	scanf("%d", &num);

	char str[num][100];
	char out[num][10];

	// out = output string.
	for (int i=0; i<num; i++) {
		char str[100];
		scanf("%s", &str);

		int len = strlen(str);

		if (len > 10) {
			out[0] = str[0]; // first letter.
			out[1] = len / 10; // tens place.
			out[2] = len % 10; // ones place.
			out[3] = str[3]; // last letter.
		}

		// Need to print
	}

}