#include <stdio.h>
#include <math.h>

int main(void) {
	int N, doubt =0;
	char line[20];

	scanf("%d", &N);

	scanf("%s", &line[0]);

	for (int i =0; i<N; i++) {
		if (line[i] == '?') {
			doubt++;
		}
	}

	if (doubt != 0) {
		char tot[4*doubt][20];
		int x[4*doubt], y[4*doubt];

		for (int i=0; i< 4*doubt; i++) {
			x[i]=0;
			y[i]=0;
		}

		for (int i=0; i<4*doubt; i++) {
			int ele = i;
			int d = doubt;
			for (int j=0; j<N; j++)	{
				if (line[i] == '?') {
					if (ele % ((int)pow(4, d)) == 0) {
						x[i]++;
						if (ele > 0) {
						ele -= pow(4, d);
						}
						d--;
					}
					if (ele % ((int)pow(4, d)) == 1) {
						x[i]--;
						if (ele > 0) {
						ele -= pow(4, d);
						}
						d--;
					}
					if (ele % ((int)pow(4, d)) == 2) {
						y[i]++;
						if (ele > 0) {
						ele -= pow(4, d);
						}
						d--;
					}
					if (ele % ((int)pow(4, d)) == 3) {
						y[i]--;
						if (ele > 0) {
						ele -= pow(4, d);
						}
						d--;
					}
				}
				else {
					if (line[i] == 'L') {
						x[i]++;
					}
					if (line[i] == 'R') {
						x[i]--;
					}
					if (line[i] == 'U') {
						y[i]++;
					}
					if (line[i] == 'D') {
						y[i]--;
					}
				}
			}
		}

		int no = 0;
		for (int i=0; i<4*doubt;i++) {
			for (int j=0; j< 4*doubt-1;j++) {
				if (x[i] == x[j]) {
					if (y[i] == y[j]) {
						no++;
					}
				}
			}
		}

		printf("%d", (4*doubt) - no);
	}
	else {
		printf("1");
	}
}