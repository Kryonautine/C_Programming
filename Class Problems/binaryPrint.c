#include <stdio.h>
#include <stdlib.h>

int power(int x, int y) {
	int ret=x;

	if ((y==0) ||(y==1)) {
		if (y==1) {
			return x;
		}
		else {
			return 1;
		}
	}
	else {
		for (int i=2; i<=y ;i++) {
			ret *= x;
		}
		return ret;
	}
}

void printbin(int a) {
	// +ve = 0, -ve = 1, 31 bits is intmax. Ex : INT_MAX = 01111..... and -INT_MAX = 11111..., -1 = 1000000....0001
	int rem;
	if (a<0) {
		printf("1");
		rem = -a;
	}
	else {
		printf("0");
		rem = a;
	}
	for (int i=30;i>=0;i--) {
		if (((int) ((double) rem/power(2, i))) != 0) {
			rem -= power(2, i); 
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}

int main(void) {
	srand(24);
	int key[128];
	int a[4];
	for(int i=0;i<4;i++) {
		//a[i] = rand();
		scanf("%d", &a[i]);
	}
	for (int i=0; i<4; i++) {
		printbin(a[i]);
	}
}