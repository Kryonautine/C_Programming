#include <stdio.h>

int main(void) {
	int i=0, j=0, l=0, n, m, k, numsubday=0, sub=0;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);

	char ticheff[n], gonf[m];

	scanf("%s", ticheff);
	scanf("%s", gonf);

	for(i=m-1; i<n; i++) {
		sub=0;
		l=0;
		for (j=i-m+1; j<i+1;j++) {
			if (((ticheff[j] - gonf[l]) == k) || ((ticheff[j] - gonf[l]) == -k)) {
				sub++;
			}
			else {
				break;
			}
			l++;
		}
		if (sub == m) {
			numsubday++;
		}
	}

	printf("%d", numsubday);

	/*
	*printf("%s\n", ticheff);
	*printf("%s\n", gonf);
	*/
}