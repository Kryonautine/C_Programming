#include <stdio.h>

#define MAXARRAY_SIZE 100

int readArray(int* numArray) {
	int size=0;
	while(scanf("%d", &numArray[size++]) != EOF) {}

	return --size;
}

void printArray(int* numArray, int size) {
	int i=0;
	while(i<size) {
		printf("%d\n", numArray[i]);
		i++;
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *array, int size) {
	int noswap=0;
	// When you don't swap throughout an entire loop, it means that the array is sorted.
	while (noswap != size-1) {
		noswap=0;
		for(int i =0; i<size-1;i++) {
			if (array[i]>array[i+1]) {
				swap(&array[i], &array[i+1]);
			}
			else {
				noswap++;
			}
		}
	}
}

int main(void) {
	int numArray[MAXARRAY_SIZE];

	int size = readArray(numArray);

	printf("======\n");
	bubbleSort(numArray, size);
	
	printArray(numArray, size);
}