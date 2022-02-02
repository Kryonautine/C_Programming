#include <stdio.h>

// No Horner's yet.

int power(int ele, int exp) {
	int i=1, retval=1;
	if (exp==0) {
		retval = 1;
	}
	else {
		for (i=1;i<=exp;i++) {
			retval *= ele;
		}
	}
	return retval;
}

int main(void) {
	int ele, i, val, polyval=0;
	scanf("%d", &ele);
	long int polyarray[ele];

	for (i=0;i<ele+1;i++) {
		scanf("%ld", &polyarray[i]);
	}
	scanf("%d", &val);

	for (i=0;i<ele+1;i++) {
		polyval += polyarray[i]*(power(val, i));
	}

	printf("%d", polyval);
}