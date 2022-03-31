#include <stdio.h>
#include <string.h>

#define MAXARRAY_SIZE 100
#define MAXLEN 100

int readArray(char charArray[MAXARRAY_SIZE][MAXLEN]) {
	int size=0;
	while(scanf("%s", &charArray[size++][0]) != EOF) {}

	return --size;
}

void printArray(char numArray[MAXARRAY_SIZE][MAXLEN], int size) {
	int i=0;
	while(i<size) {
		printf("%s\n", &numArray[i][0]);
		i++;
	}
}

void swap(char* a, char* b) {
	char temp[MAXLEN];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void bubbleSort(char array[MAXARRAY_SIZE][MAXLEN], int size) {
	int noswap=0;
	// When you don't swap throughout an entire loop, it means that the array is sorted.
	while (noswap != size-1) {
		noswap=0;
		for(int i =0; i<size-1;i++) {
			if ((strcmp(&array[i][0], &array[i+1][0]))>0) {
				swap(&array[i][0], &array[i+1][0]);
			}
			else {
				noswap++;
			}
		}
	}
}

/*
* To pass a string, use the address of the base element.
* Ex: char s[2][100]; scanf("%s", &s[1][0]);scanf("%s", &s[0][0]);
* This scans the 2nd element of the string and then the first.
*/

// Sorted using bubbleSort.
int main(void) {
	char charArray[MAXARRAY_SIZE][MAXLEN];

	int nonames = readArray(charArray);

	printf("======\n");
	bubbleSort(charArray, nonames);
	
	printArray(charArray, nonames);
}