#include <stdio.h>

int main(int argc, char** argv) {
	FILE *fptr = fopen(argv[1], "r");
	FILE *fp2tr = fopen(argv[2], "w");

	for (int i=0; i<100;i++) {
		fscanf(fptr, "%d\n", &i);
		fprintf(fp2tr, "%d\t", i);
	}	
}