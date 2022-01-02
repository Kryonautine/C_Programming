#include <stdio.h>
#include <math.h>

int readMarks(long int marks[],long int stdNo) {
	int flag=0;
	long int i=0;

	for (i=0;i<stdNo;i++) {
		scanf("%ld", &marks[i]);
		if ((marks[i]<0) || (marks[i]>100)) {
			printf("INVALID INPUT");
			flag++;
			break;
		}
	}

	return(flag);
}

int main(void) {
	int flag=0, hist[11], low=0, high=9, j=0;
	long int stdNo, i=0;

	scanf("%ld",&stdNo);

	long int marks[stdNo];
	
	flag = readMarks(marks, stdNo);

	for (j=0;j<11;j++) {
		hist[j]=0;
		for (i=0;i<stdNo;i++) {
			if ((low<=marks[i]) && (marks[i]<=high)) {
				hist[j]++;
			}
		}
		low +=10;
		high+=10;
	}

	if (flag==0) {
		for (j=0;j<11;j++) {
			printf("%d ", hist[j]);
		}
	}
}