#include <stdio.h>

int main(void) {
	int i=0, j=0, l=0, n, k, maxqn=0, qans, anslen=0, dont;

	scanf("%d", &n);
	scanf("%d", &k);

	int call = k;
	char qno[n];

	scanf("%s", qno);

	// Needs severe testing
	for (j=0;j<n;j++) {
		qans=0;
		{
		char knowans[k];
		anslen=0;
		for (i=j;i<n;i++) {
			dont =0;
			for (l=0;l<=anslen;l++) {
				if (knowans[l] == qno[i]) {
					qans++;
					break;
				}
				else {
					dont++;
				}
			}
			if ((dont-1) == anslen) {
				if (call>0) {
					call--;
					knowans[anslen] = qno[i];
					anslen++;
				}
				else {
					goto exitpoint;
				}
			}
		}
		exitpoint:
			;
		}

		if (qans>maxqn) {
			maxqn=qans;
		}
	}

	printf("%d", maxqn);
}