#include <stdio.h>

int main(int argc, char **argv) {
	// Output file is argv[1] , input is argv[2] - argv[argc-1]
	FILE *fptr;
	char var;
	int zeronine[10], capsAZ[26], smallaz[26];

	for (int i=0;i<10;i++) {
		zeronine[i]= 0;
	}
	for (int i=0;i<26;i++) {
		capsAZ[i]= 0;
	}
	for (int i=0;i<26;i++) {
		smallaz[i]= 0;
	}

	for (int i = 2; i<argc; i++) {
		fptr = fopen(argv[i], "r");
		while (1) {
			int retval = fscanf(fptr, "%c", &var);
			if (retval == -1) {
				break;
			}
			for (int j=48; j<58; j++) {
				if (((int) var) == j) {
					zeronine[j-48]++;
					break;
				}
			}
			for (int j=65; j<91; j++) {
				if (((int) var) == j) {
					capsAZ[j-65]++;
					break;
				}
			}
			for (int j=97; j<123; j++) {
				if (((int) var) == j) {
					smallaz[j-97]++;
					break;
				}
			}
		}
	
	fclose(fptr);

	}

	fptr = fopen(argv[1], "w");	
	for (int j=48; j<58; j++) {
		fprintf(fptr, "%d:%d\n", j-48, zeronine[j-48]);
	}
	for (int j=65; j<91; j++) {
		fprintf(fptr, "%c:%d\n", ((char) j), capsAZ[j-65]);
	}
	for (int j=97; j<123; j++) {
		fprintf(fptr, "%c:%d\n", ((char) j), smallaz[j-97]);
	}
	fclose(fptr);
}
