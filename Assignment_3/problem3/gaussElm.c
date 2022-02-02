#include <stdio.h>

int main(void) {
	int noOfEqn, i=0, j=0, k=0, l=0, swapRow=0;

	scanf("%d", &noOfEqn);

	double EqnMatrix[noOfEqn][noOfEqn], constant[noOfEqn], ansMat[noOfEqn], mulConst=0, temp=0, max, backSum=0;

	// Scanning matrix inputs.
	for (i=0;i<noOfEqn;i++) {
		for (j=0;j<noOfEqn;j++) {
			scanf("%lf", &EqnMatrix[i][j]);
		}
	}

	// Scanning constant inputs.
	for (i=0;i<noOfEqn;i++) {
		scanf("%lf", &constant[i]);
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
			temp = constant[swapRow];
			constant[swapRow] = constant[k];
			constant[k] = temp;
		}
	
		for (i=k;i<noOfEqn;i++) {
			if (i != noOfEqn-1) {
				mulConst = EqnMatrix[i+1][k]/EqnMatrix[k][k];
				constant[i+1] -= mulConst*constant[k];
				for (j=k;j<noOfEqn;j++) {
					EqnMatrix[i+1][j] = EqnMatrix[i+1][j] - mulConst*EqnMatrix[k][j];
				}
			}
		}
	}

	// Do Backwards Substitution.
	for (i=0;i<noOfEqn;i++) {
		backSum=0;
		for (j=0;j<noOfEqn;j++) {
			if (noOfEqn-j-1 == noOfEqn-i-1) {
				break;
			}
			else {
				backSum += ansMat[noOfEqn-j-1] * EqnMatrix[noOfEqn-i-1][noOfEqn-j-1];
			}
		}
		ansMat[noOfEqn-i-1] = (constant[noOfEqn-i-1] - backSum)/ EqnMatrix[noOfEqn-i-1][noOfEqn-i-1];
	}

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

	for (i=0;i<noOfEqn;i++) {
		printf("%lf\n", ansMat[i]);
	}
}