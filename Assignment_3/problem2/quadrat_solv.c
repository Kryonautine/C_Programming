#include <stdio.h>
#include <math.h>

// ax^2 + bx + c

int main(void) {
	int totquad, i=0;
	long int realcheck;

	scanf("%d", &totquad);

	int inita[totquad], initb[totquad], initc[totquad];
	double a, b, c, root1, root2, iroot1, iroot2;

	for (i=0;i<totquad;i++) {
		scanf("%d", &inita[i]);
		scanf("%d", &initb[i]);
		scanf("%d", &initc[i]);
	}


	for (i=0;i<totquad;i++) {
		a = 1.0 * inita[i];
		b = 1.0 * initb[i];
		c = 1.0 * initc[i];
		realcheck = (long int) b*b - 4*a*c;

		if (realcheck >= 0) {
			// roots are real
			iroot1=0.0;
			iroot2=0.0;
			root1 = (-b + sqrt(b*b-4*a*c))/(2*a);
			if (realcheck==0) {
				root2=root1;
			}
			else {
				root2 = (-b - sqrt(b*b-4*a*c))/(2*a);
			}
		}
		else {
			//roots are imaginary
			root1 = (-b)/(2*a);
			root2 = root1;
			iroot1 = sqrt(4*a*c-b*b)/(2*a);
			iroot2 = (-sqrt(4*a*c-b*b))/(2*a);
		}

		printf("%.6f ", root1);
		printf("%.6f \n", iroot1);
		printf("%.6f ", root2);
		printf("%.6f\n", iroot2);
	}

}