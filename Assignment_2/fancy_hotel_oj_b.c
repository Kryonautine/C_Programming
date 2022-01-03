#include <stdio.h>

int main(void) {
	long int floor, room, i=0, j=0;

	scanf("%ld", &floor);
	scanf("%ld", &room);

	int hotel[floor][room], fem_floor[floor], mal_floor[floor];
	double mal_percent, fem_percent;

	for (i=0;i<floor;i++) {
		mal_floor[i]=0;
		fem_floor[i]=0;
		for (j=0;j<room;j++) {
			scanf("%d", &hotel[i][j]);
			if (hotel[i][j] != 0) {
				if (hotel[i][j] == 1) {
					fem_floor[i]++;
				}
			}
			else {
				mal_floor[i]++;
			}
		}
	}

	for (i=0;i<floor;i++) {
		mal_percent = (mal_floor[i]*100.0)/room;
		fem_percent = (fem_floor[i]*100.0)/room;
		printf("%2.5f ", mal_percent);
		printf("%2.5f\n", fem_percent);
	}
}