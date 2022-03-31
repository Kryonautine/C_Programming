#include <stdio.h>

#define MAX_LEN 50
#define MAXARRAY_SIZE 50

int read_names(char names[MAXARRAY_SIZE][MAX_LEN]) {
	int nameNum=0;
	while(scanf("%s", &names[nameNum][0]) != EOF) {
		nameNum++;
	}

	return nameNum;
}

void print_names(char names[MAXARRAY_SIZE][MAX_LEN], int size) {
	int i=0;
	
	printf("======\n");
	for (i=0;i<size;i++) {
		printf("%s\n", names[i]);
	}
	printf("======\n");
}

int main(void) {
	char name_array[MAXARRAY_SIZE][MAX_LEN];

	int size = read_names(name_array);

	print_names(name_array, size);
}