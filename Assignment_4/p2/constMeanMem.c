#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fptr;
	long num=0;
	int retval=0;
	double mean, buffer, sum=0;

	fptr = fopen(argv[1], "r");
	while (1) {
		retval = fscanf(fptr, "%lf", &buffer);
		if (retval == -1) {
			break;
		}
		sum += buffer;
		num++;
	}
	fclose(fptr);

	mean = sum/num;

	fptr = fopen(argv[2], "w");
	fprintf(fptr, "%lf\n", mean);
	fclose(fptr);
}