#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *f1ptr, *f2ptr, *wrptr;
	int retval1=0, retval2=0, inc1=-1, inc2=1;
	char var1[16], var2[16];

	f1ptr = fopen(argv[1], "r");
	f2ptr = fopen(argv[2], "r");
	wrptr = fopen(argv[3], "w");

	while(1) {
		if (inc1<0) {
			retval1 = fscanf(f1ptr, "%s", var1);
			inc1=0;
		}
		if (inc2>=0) {
			retval2 = fscanf(f2ptr, "%s", var2);
			inc2=0;
		}

		if (retval1 == -1) {
			while (retval2 != -1) {
				fprintf(wrptr, "%s\n", var2);
				retval2 = fscanf(f2ptr, "%s", var2);
				//print rest of file2.
			}
			break;
		}
		if (retval2 == -1) {
			while (retval1 != -1) {
				fprintf(wrptr, "%s\n", var1);
				retval1 = fscanf(f1ptr, "%s", var1);
				//print rest of file1.
			}
			break;
		}

		inc1 = strcmp(var1, var2);	
		inc2 = inc1;

		if (inc1<0) {
			fprintf(wrptr, "%s\n", var1);
		}
		if (inc2>=0) {
			fprintf(wrptr, "%s\n", var2);
		}
	}

	fclose(f1ptr);
	fclose(f2ptr);
	fclose(wrptr);
}