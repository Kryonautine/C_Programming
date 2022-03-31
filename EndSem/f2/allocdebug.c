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
		int tot = pow(4, doubt);
		int x[tot], y[tot];

		for (int i=0; i< tot; i++) {
			x[i]=0;
			y[i]=0;
		}

		for (int i=0; i<tot; i++) {
			int ele = i;
			int d = doubt;
			for (int j=0; j<N; j++)	{
				if (line[j] == '?') {

					int mod = ((int) pow(4, d));

					if (ele % mod == 0) {
						x[i]++;
						if (ele > 0) {
						ele -= mod;
						}
						d--;
						continue;
					}
					if (ele % mod == 1) {
						x[i]--;
						if (ele > 0) {
						ele -= mod;
						}
						d--;
						continue;
					}
					if (ele % mod == 2) {
						y[i]++;
						if (ele > 0) {
						ele -= mod;
						}
						d--;
						continue;
					}
					if (ele % mod== 3) {
						y[i]--;
						if (ele > 0) {
						ele -= mod;
						}
						d--;
						continue;
					}
				}
				else {
					if (line[j] == 'L') {
						x[i]++;
						continue;
					}
					if (line[j] == 'R') {
						x[i]--;
						continue;
					}
					if (line[j] == 'U') {
						y[i]++;
						continue;
					}
					if (line[j] == 'D') {
						y[i]--;
						continue;
					}
				}
			}
		}

		int no = 0;
		for (int i=0; i<tot;i++) {
			for (int j=i+1; j< tot;j++) {
				if (x[i] == x[j]) {
					if (y[i] == y[j]) {
						no++;
					}
				}
			}
		}

		printf("%d", (tot) - no);
	}
	else {
		printf("1");
	}
}