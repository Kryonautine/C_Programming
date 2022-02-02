#include <stdio.h>


// Doesn't Work, do not use.
int main(void) {
	int noOfEqn, i=0, j=0, k=0, l=0, swapRow=0;

	scanf("%d", &noOfEqn);

	int det=1;
	long double EqnMatrix[noOfEqn][noOfEqn], mul=0, temp=0, max;

	// Scanning matrix inputs.
	for (i=0;i<noOfEqn;i++) {
		for (j=0;j<noOfEqn;j++) {
			scanf("%Lf", &EqnMatrix[i][j]);
		}
	}

	// Using Gaussian Elimination.(Forward Elimination)
	for (k=0;k<noOfEqn-1;k++) {
		// Swapping rows/partial pivoting.
		max = EqnMatrix[k][k];
		swapRow=k;
		for (l=k;l<noOfEqn;l++) {
			if (max<EqnMatrix[l][k]) {
				max = EqnMatrix[l][k];
				swapRow=l;
			}
		}
		if (swapRow != k) {
			for (i=0;i<noOfEqn;i++) {
				temp = EqnMatrix[swapRow][i];
				EqnMatrix[swapRow][i] = EqnMatrix[k][i];
				EqnMatrix[k][i] = temp;
			}
		}
	
		for (i=k;i<noOfEqn;i++) {
			if (i != noOfEqn-1) {
				mul = EqnMatrix[i+1][k]/EqnMatrix[k][k];
				for (j=k;j<noOfEqn;j++) {
					EqnMatrix[i+1][j] = EqnMatrix[i+1][j] - mul*EqnMatrix[k][j];
				}
			}
		}
	}

	// Determinant Calculation.
	for (i=0;i<noOfEqn;i++) {
		det = det* EqnMatrix[i][i];
		if (det>100000007) {
			det = det % 100000007;
		}
	}

	printf("%d", det);
	// Testing matrix outputs.
	/*
	for (i=0;i<noOfEqn;i++) {
		for (j=0;j<noOfEqn;j++) {
				printf("%lf ", EqnMatrix[i][j]);
			}
		printf("\n");
	}
	for (i=0;i<noOfEqn;i++) {
		printf("%lf ", constant[i]);
	}
	printf("\n");
  */
}