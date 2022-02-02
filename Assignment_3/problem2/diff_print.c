#include <stdio.h>

int main(void) {
	int ele, i, flag=0, endflag=1, allzero=0;
	scanf("%d", &ele);
	long int polyarray[ele-1], initarray[ele];

	for (i=0;i<ele;i++) {
		scanf("%ld", &initarray[i]);
	}

	for (i=0;i<ele;i++) {
		polyarray[i] = initarray[i+1]*(i+1);
	}

	ele--;
	for (i=ele-1;i>=0;i--) {
		if (flag != 0) {
			switch (-polyarray[i]) {
				case 0:
					endflag=0;
					break;
				case -1:
					printf("+ ");
					endflag++;
					break;
				case 1:
					printf("- ");
					endflag++;
					break;
				default:
					if (polyarray[i]>0) {
						printf("+ %ld", polyarray[i]);
					}
					else {
						printf("- %ld", -polyarray[i]);
					}
					endflag++;
			}
		}
		else {
			switch (polyarray[i]) {
				case 0:
					break;
				case 1:
					flag++;
					break;
				case -1:
					printf("-");
					flag++;
					break;
				default:
					printf("%ld", polyarray[i]);
					flag++;
			}
		}

		if (polyarray[i] != 0) {
			switch (i) {
				case 1:
					printf("x ");
					break;
				case 0:
					if (((polyarray[i] == 1) || (polyarray[i] == -1)) && (flag == 1)) {
						printf("1");
					}
					break;
				default:
					printf("x^%d ", i);
			}
		}
		else {
			allzero++;
			if (allzero == ele) {
				printf("0");
			}
			endflag++;
		}

		if ((endflag == 0) && (i==0)) {
			printf("\b");
		}
	}
}