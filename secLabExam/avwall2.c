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
	double t, ceiling, dist=1;
	double miny=1, maxy=0, minele, maxele;

	scanf("%d", &n);

	double y[n], v[n];

	for (int i=0; i<n;i++) {
		scanf("%lf", &y[i]);
		scanf("%lf", &v[i]);
	}

	int intt=0;

	while (miny > maxy) {
		miny = y[0] - v[0]*intt;
		maxy = y[0] + v[0]*intt;

		for (int i=1; i<n; i++) {
			double t1, t2;

			minele = y[i] - v[i]*intt;
			maxele = y[i] + v[i]*intt;

			t1 = mini(maxy, maxele);
			maxy = t1;
			t2 = maxi(miny, minele);
			miny = t2;

			if (miny > maxy) {
				break;
			}
		}

		intt++;
	}

	ceiling = (double) intt;

	t = (double) intt;

	for (int i=0; i<25; i++) {
		double tch = ceiling-(dist/2);
		int flag=0;

		maxy = y[0] + v[0]*tch;
		miny = y[0] - v[0]*tch;
		for (int i=1; i<n; i++) {
			double t1, t2;

			minele = y[i] - v[i]*tch;
			maxele = y[i] + v[i]*tch;

			t1 = mini(maxy, maxele);
			maxy = t1;
			t2 = maxi(miny, minele);
			miny = t2;

			if (miny > maxy) {
				flag=1;
				break;
			}
		}

		if (flag == 1) {
			dist = dist/2;
		}
		else {
			ceiling = ceiling - (dist/2);
			dist = dist/2;
		}
		t = ceiling;
	}

	printf("%0.6f", t);
}