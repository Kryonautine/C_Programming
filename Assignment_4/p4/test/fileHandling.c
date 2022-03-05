#include <stdio.h>

int main(int argc, char** argv) {
	FILE *fptr = fopen(argv[1], "w");

	for (int i=0; i<100;i++) {
		fprintf(fptr, "%d\n", i);
	}	
}