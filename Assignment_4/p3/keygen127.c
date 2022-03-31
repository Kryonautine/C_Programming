#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	srand(393);
	int key[127], var, rand01[2], form01[2], keymil[1000000];
	double randm[2], form[2];
	for (int i=0;i<127;i++) {
		key[i] = (rand() % 2);
		keymil[i] = key[i];
	}

	rand01[0]=0;
	rand01[1]=0;
	for (int i=127;i<=1000000;i++) {
		var = (rand() % 2);
		if (var ==0) {
			rand01[0]++;
		}
		else {
			rand01[1]++;
		}
	}

	form01[0]=0;
	form01[1]=0;
	for (int i=127;i<=1000000;i++) {
		keymil[i] = keymil[i-1] ^ keymil[i-127];
		if (keymil[i] ==0) {
			form01[0]++;
		}
		else {
			form01[1]++;
		}
	}

	randm[0] = (double) 100.0*rand01[0]/(rand01[0]+rand01[1]);
	randm[1] = (double) 100.0*rand01[1]/(rand01[0]+rand01[1]);
	form[0] = (double) 100.0*form01[0]/(form01[0]+form01[1]);
	form[1] = (double) 100.0*form01[1]/(form01[0]+form01[1]);

	printf("Probability of 0 through rand method : %lf\n", randm[0]);
	printf("Probability of 1 through rand method : %lf\n", randm[1]);
	printf("Probability of 0 through formula method : %lf\n", form[0]);
	printf("Probability of 1 through formula method : %lf\n", form[1]);
}