#include <stdio.h>

#define MAX_LEN 50
#define MAXARRAY_SIZE 50

int read_names(char names[MAXARRAY_SIZE][MAX_LEN]) {
	int nameNum=0;
	scanf("%s", names[i]);
}

int main(void) {
	char str[MAX_LEN];

	scanf("%s", str);

	printf("Becky, %s and John\n", str);

	for (int i=0; str[i] != '\0'; i++) {
		printf("%c", str[i]);
	}

	printf("\n");
	for (char* chptr = str; *chptr != '\0'; ++chptr) {
		printf("%c", *chptr);
	}
	printf("\n");
}