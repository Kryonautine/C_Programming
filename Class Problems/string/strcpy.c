#include <stdio.h>

#define MAXLEN 100

char* strcpy(char* a, char* b) {
	int i=0;

	for (i=0; b[i] != '\0'; i++) {
		a[i] = b[i];
	}
	i++;
	a[i]=b[i];
}

int main(void) {
	char a[MAXLEN], b[MAXLEN];

	printf("a=");
	scanf("%s", a);

	printf("b=");
	scanf("%s", b);

	strcpy(a, b);
}