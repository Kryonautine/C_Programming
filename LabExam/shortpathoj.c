#include <stdio.h>
#include <math.h>

int main(void) {
	long n, root, path, prime, large = 1;
	scanf("%ld", &n);

	root = (long) sqrt(n);

	prime = 1;
	for (int i = 2; i< root+1;i++) {
		if (n % i == 0) {
			large = i;
		}
		else {
			prime++;
		}
	}

	if (prime == root) {
		path = n-1;
	}
	else {
		path = large + ((long) n/large) - 2;
	}

	printf("%ld\n", path);
}