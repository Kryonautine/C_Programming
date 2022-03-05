#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	srand(39288);
	int key[127], var, prevar, rand01[2], ro[2], fo[2], form01[2], keymil[1000000];
	double randm[2], form[2];
	for (int i=0;i<127;i++) {
		key[i] = (rand() % 2);
		keymil[i] = key[i];
	}

	rand01[0]=0;
	rand01[1]=0;
	ro[0]=0;
	ro[1]=0;
	prevar = keymil[126];
	for (int i=127;i<=1000000;i++) {
		var = (rand() % 2);
		if ((var ==0) && (prevar == 0)) {
			rand01[0]++;
		}
		if ((var ==0) && (prevar == 1)) {
			rand01[1]++;
		}
		if (var == 0) {
			ro[0]++;
		}
		if (var == 1) {
			ro[1]++;
		}
		prevar = var;
	}

	form01[0]=0;
	form01[1]=0;
	fo[0]=0;
	fo[1]=0;
	for (int i=127;i<=1000000;i++) {
		keymil[i] = keymil[i-1] ^ keymil[i-127];
		if ((keymil[i] ==0) && (keymil[i-1]==0)) {
			form01[0]++;
		}
		if ((keymil[i] ==0) && (keymil[i-1]==1)) {
			form01[1]++;
		}
		if (keymil[i]==0) {
			fo[0]++;
		}
		if (keymil[i]==1) {
			fo[1]++;
		}
	}

	randm[0] = (double) 100.0*rand01[0]/ro[0];
	randm[1] = (double) 100.0*rand01[1]/ro[1];
	form[0] = (double) 100.0*form01[0]/fo[0];
	form[1] = (double) 100.0*form01[1]/fo[1];

	printf("Probability of x(i)=0/x(i-1)=0 through rand method : %lf\n", randm[0]);
	printf("Probability of x(i)=0/x(i-1)=1 through rand method : %lf\n", randm[1]);
	printf("Probability of x(i)=0/x(i-1)=0 through formula method : %lf\n", form[0]);
	printf("Probability of x(i)=0/x(i-1)=1 through formula method : %lf\n", form[1]);
}