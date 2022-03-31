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
	int n;
	double t;
	double miny, maxy, minele, maxele;

	scanf("%d", &n);
	scanf("%lf", &t);

	int y[n], v[n];

	for (int i=0; i<n; i++) {
		scanf("%d", &y[i]);
		scanf("%d", &v[i]);
	}

	miny = y[0] - v[0]*t;
	maxy = y[0] + v[0]*t;

	for (int i=1; i<n; i++) {
		int t1, t2;
		minele = y[i] - v[i]*t;
		maxele = y[i] + v[i]*t;

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