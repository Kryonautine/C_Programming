#include <stdio.h>

int main(void) {
	int noOfEqn, i=0, j=0, k=0, l=0, swapRow=0, flag=0;

	scanf("%d", &noOfEqn);

	double uMat[noOfEqn][noOfEqn], lMat[noOfEqn][noOfEqn], detCheck[noOfEqn][noOfEqn][noOfEqn];
	double constant[noOfEqn], ansMat[noOfEqn], mulConst=0, temp=0, max, backSum=0, det;

	// Scanning matrix inputs.
	for (i=0;i<noOfEqn;i++) {
		for (j=0;j<noOfEqn;j++) {
			scanf("%lf", &uMat[i][j]);
			if (i==j) {
				lMat[i][j] = 1;
			}
			else {
				lMat[i][j] = 0;
			}
		}
	}

	/* Scanning constant inputs.
	for (i=0;i<noOfEqn;i++) {
		scanf("%lf", &constant[i]);
	}
	*/

	// Using Gaussian Elimination.(Forward Elimination)
	for (k=0;k<noOfEqn-1;k++) {
		/* Swapping rows/partial pivoting.
		Need to replace EqnMatrix with uMat
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
		*/
	
		for (i=k;i<noOfEqn;i++) {
			if (i != noOfEqn-1) {
				mulConst = uMat[i+1][k]/uMat[k][k];
				constant[i+1] -= mulConst*constant[k];
				lMat[i+1][k] = mulConst;
				for (j=k;j<noOfEqn;j++) {
					uMat[i+1][j] = uMat[i+1][j] - mulConst*uMat[k][j];
				}
			}
		}
	}

	// Copying into detCheck
	for (i=0;i<noOfEqn;i++) {
		for (j=0;j<noOfEqn-i;j++) {
			for (k=0;k<noOfEqn-i;k++) {
				detCheck[i][j][k] = uMat[j][k];
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
				backSum += ansMat[noOfEqn-j-1] * uMat[noOfEqn-i-1][noOfEqn-j-1];
			}
		}
		ansMat[noOfEqn-i-1] = (constant[noOfEqn-i-1] - backSum)/ uMat[noOfEqn-i-1][noOfEqn-i-1];
	}

	// Printing detCheck and calculating primary determinants.
	for (i=0;i<noOfEqn;i++) {
		det = 1;
		for (j=0;j<noOfEqn-i;j++) {
			for (k=0;k<noOfEqn-i;k++) {
				// printf("%lf ", detCheck[i][j][k]);
				if (j==k) {
					det *= detCheck[i][j][k];
				}
			}
			// printf("\n");
		}
		if (det == 0) {
			flag++;
			break;
		}
		// printf("%lf ", det);
		// printf("\n");
	}

	// Testing matrix outputs.
	if (flag != 0) {
		printf("No LU Decomposition\n");
	}
	else {
		for (i=0;i<noOfEqn;i++) {
			for (j=0;j<noOfEqn;j++) {
					printf("%lf ", lMat[i][j]);
				}
			printf("\n");
		}

		for (i=0;i<noOfEqn;i++) {
			for (j=0;j<noOfEqn;j++) {
					printf("%lf ", uMat[i][j]);
				}
			printf("\n");
		}
	}

	/*
	for (i=0;i<noOfEqn;i++) {
		printf("%lf ", constant[i]);
	}
	printf("\n");

	for (i=0;i<noOfEqn;i++) {
		printf("%lf\n", ansMat[i]);
	}
  */
}