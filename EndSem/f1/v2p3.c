#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void printArray(char numArray[][MAXLEN], int size, char last[][MAXLEN]) {
	int i=0;
	while(i<size) {
		printf("%s %s\n", &numArray[i][0], &last[i][0]);
		i++;
	}
}

void swap(char* a, char* b) {
	char temp[MAXLEN];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void bubbleSort(char array[][MAXLEN], int size, char last[][MAXLEN]) {
	int noswap=0;
	// When you don't swap throughout an entire loop, it means that the array is sorted.
	while (noswap != size-1) {
		noswap=0;
		for(int i =0; i<size-1;i++) {

			char str1[MAXLEN];
			char str2[MAXLEN];
			strcpy(str1, &array[i][0]);
			strcpy(str2, &array[i+1][0]);

			for (int i=0; i<MAXLEN; i++) {
				if ((str1[i] >= 65) && (str1[i] <= 97)) {
					str1[i] += 32;
				}
			}

			for (int i=0; i<MAXLEN; i++) {
				if ((str2[i] >= 65) && (str2[i] <= 97)) {
					str2[i] += 32;
				}
			}

			int temp = strcmp(str1, str2);
			if (temp >0) {
				swap(&array[i][0], &array[i+1][0]);
				swap(&last[i][0], &last[i+1][0]);
			}
			else {
				if (temp == 0){

					char str3[MAXLEN];
					char str4[MAXLEN];
					strcpy(str3, &last[i][0]);
					strcpy(str4, &last[i+1][0]);

					for (int i=0; i<MAXLEN; i++) {
						if ((str3[i] >= 65) && (str3[i] <= 97)) {
							str3[i] += 32;
						}
					}

					for (int i=0; i<MAXLEN; i++) {
						if ((str4[i] >= 65) && (str4[i] <= 97)) {
							str4[i] += 32;
						}
					}

					int temp1 = strcmp(str3, str4);
					if (temp1 <0) {
						swap(&array[i][0], &array[i+1][0]);
						swap(&last[i][0], &last[i+1][0]);
					}
					else {
						noswap++;
					}

				}
				else {
					noswap++;
				}
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

	int N;
	scanf("%d", &N);

	char firstArray[N][MAXLEN];
	char lastArray[N][MAXLEN];

	for (int i=0; i<N; i++) {
		scanf("%s", &firstArray[i][0]);
		scanf("%s", &lastArray[i][0]);
	}

	bubbleSort(firstArray, N, lastArray);
	
	printArray(firstArray, N, lastArray);
}