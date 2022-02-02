#include <stdio.h>

int main(void) {
	int i=0, j=0, empFloor[100], empest=-1;

	int hotel[100][30];

	for (i=0;i<100;i++) {
	
		empFloor[i] = 0;
	
		for (j=0;j<30;j++) {
			scanf("%d", &hotel[i][j]);
			if (hotel[i][j] == 0)
				empFloor[i]++;
		}
	
		if ((empFloor[i] > 0) && (empFloor[i] > empFloor[empest]))
			empest = i;
	}

	printf("%d", empest);
}