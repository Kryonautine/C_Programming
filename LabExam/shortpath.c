#include <stdio.h>
#include <math.h>

int main(void) {
	long n, root, p, q, path, prime, no=0, large;
	scanf("%ld", &n);

	root = (long) sqrt(n);
	p = root;
	q = root;

	prime = 1;
	for (int i = 2; i< p+1;i++) {
		if (n % i == 0) {
			large = i;
			//printf("%ld = large\n", large);
		}
		else {
			prime++;
		}
	}

	//printf("%ld = prime\n", prime);
	if (prime == p) {
		path = n-1;
	}
	else {
		path = large + ((long) n/large) - 2;
	}

	/*
	if (no == 0) {
		while (p*q != n) {
			if (p*q > n) {
				if (p == 1) {
					q--;
				}
				else {
					p--;
				}
			}
			else {
				q++;
			}
		}
		path = p+q -2;
	}
	else {
		path = n-1;
	}
	*/
	printf("%ld\n", path);
}