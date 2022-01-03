#include <stdio.h>

int main(void) {
	long int floor, room, i=0, j=0, maxfNum=0, maxmNum=0, maxm_floor=1, maxf_floor=1;

	scanf("%ld", &floor);
	scanf("%ld", &room);

	int hotel[floor][room], fem_floor[floor], mal_floor[floor];

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

	for (i=0;i<floor;i++){
		if (mal_floor[i] > maxmNum){
			maxmNum = mal_floor[i];
			maxm_floor = i+1;
		}
		if (fem_floor[i] > maxfNum){
			maxfNum = fem_floor[i];
			maxf_floor = i+1;
		}
	}

	printf("%ld ", maxm_floor);
	printf("%ld", maxf_floor);
}