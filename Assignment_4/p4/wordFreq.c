#include <stdio.h>
#include <string.h>

#define MAXARRAY_SIZE 1000
#define MAXLEN 21

void swap(char* a, char* b) {
	char temp[MAXLEN];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

void intswap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void arrSort(char array[MAXARRAY_SIZE][MAXLEN], int wordnumArr[MAXARRAY_SIZE],int size) {
	int noswap=0;
	// When you don't swap throughout an entire loop, it means that the array is sorted.
	while (noswap != size-1) {
		noswap=0;
		for(int i =0; i<size-1;i++) {
			if ((strcmp(&array[i][0], &array[i+1][0]))>0) {
				swap(&array[i][0], &array[i+1][0]);
				intswap(&wordnumArr[i], &wordnumArr[i+1]);
			}
			else {
				noswap++;
			}
		}
	}
}

int main(int argc, char **argv) {
	// Output file is argv[1] , input is argv[2] - argv[argc-1]
	FILE *fptr;

	char wordArr[1000][21], varstr[21];
	int nostr=0, cmpval, unqval=0, nowordArr[1000];

	for (int i = 2; i<argc; i++) {
		fptr = fopen(argv[i], "r");
		while (1) {
			unqval=0;
			int retval = fscanf(fptr, "%s", varstr);
			if (retval == -1) {
				break;
			}
			for (int j=0; j<nostr;j++) {
				cmpval = strcmp(varstr, wordArr[j]);
				if(cmpval==0) {
					nowordArr[j]++;
					break;
				}
				else {
					unqval++;
				}
			}
			if (unqval ==nostr) {
				char *src;
				src = varstr;
				strcpy(wordArr[nostr], src);
				nowordArr[nostr]=1;
				nostr++;
			}
		}
	fclose(fptr);
	}

	arrSort(wordArr, nowordArr, nostr);
	fptr = fopen(argv[1], "w");	
	for (int i=0; i<nostr; i++) {
		fprintf(fptr, "%s:%d\n", wordArr[i], nowordArr[i]);
	}
	fclose(fptr);
}
