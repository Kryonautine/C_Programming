#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fptr, *altfptr;
	int num=0, retval=0;
	double mean, buffer, buf2, sum=0, variance=0, varsum=0;

	fptr = fopen(argv[1], "r");
	while (1) {
		retval = fscanf(fptr, "%lf", &buffer);
		if (retval == -1) {
			break;
		}
		sum += buffer;
		num++;
		mean = sum/num;

		altfptr = fopen(argv[1], "r");
		varsum=0;
		for (int i=0;i<num;i++) {
			fscanf(altfptr, "%lf", &buf2);
			varsum += (buf2 - mean)*(buf2 - mean);
		}
		variance = varsum/num;
		fclose(altfptr);

		altfptr = fopen(argv[4], "a");
		fprintf(altfptr, "%lf\n", variance);
		fclose(altfptr);
	}
	fclose(fptr);

	fptr = fopen(argv[2], "w");
	fprintf(fptr, "%lf\n", mean);
	fclose(fptr);

	fptr = fopen(argv[3], "w");
	fprintf(fptr, "%lf\n", variance);
	fclose(fptr);
}