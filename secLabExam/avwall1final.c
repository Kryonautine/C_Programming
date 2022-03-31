#include <stdio.h>

double maxi(double a, double b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

double mini(double a, double b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main(void) {
	double n;
	double y, v;
	double t;
	double miny, maxy, minele, maxele;

	scanf("%lf", &n);
	scanf("%lf", &t);

	scanf("%lf", &y);
	scanf("%lf", &v);

	miny = y - v*t;
	maxy = y + v*t;

	for (double i=1; i<n; i++) {
		double t1, t2;
		scanf("%lf", &y);
		scanf("%lf", &v);

		minele = y - v*t;
		maxele = y + v*t;

		t1 = mini(maxy, maxele);
		maxy = t1;
		t2 = maxi(miny, minele);
		miny = t2;
	}

	if (miny > maxy) {
		printf("NO");
	}
	else {
		printf("YES");
	}
}