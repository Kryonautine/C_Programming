#include <stdio.h>

int main(void) {
	int noOfEqn, i=0, j=0, k=0, flag=0;

	scanf("%d", &noOfEqn);

	double uMat[noOfEqn][noOfEqn], lMat[noOfEqn][noOfEqn], detCheck[noOfEqn][noOfEqn][noOfEqn], det;

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

	// Using Gaussian Elimination.(Forward Elimination)
	for (k=0;k<noOfEqn-1;k++) {
		for (i=k;i<noOfEqn;i++) {
			if (i != noOfEqn-1) {
				lMat[i+1][k] = uMat[i+1][k]/uMat[k][k];
				for (j=k;j<noOfEqn;j++) {
					uMat[i+1][j] = uMat[i+1][j] - lMat[i+1][k]*uMat[k][j];
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

	// Printing detCheck and calculating primary determinants.
	for (i=0;i<noOfEqn;i++) {
		det = 1;
		for (j=0;j<noOfEqn-i;j++) {
			det *= detCheck[i][j][j];
		}
		if (det == 0) {
			flag++;
			break;
		}
	}

	// Matrix outputs.
	if (flag != 0) {
		printf("No LU decomposition");
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
}