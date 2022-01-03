#include <stdio.h>

int main(void) {
	long int floor, room, mal=0, fem=0, emp=0, i=0, j=0;

	scanf("%ld", &floor);
	scanf("%ld", &room);

	int hotel[floor][room];

	for (i=0;i<floor;i++) {
		for (j=0;j<room;j++) {
			scanf("%d", &hotel[i][j]);
			if (hotel[i][j] != 0) {
				if (hotel[i][j] != 1) {
					emp++;
				}
				else {
					fem++;
				}
			}
			else {
				mal++;
			}
		}
	}

	if ((mal % room==0) || (emp>= (room-(mal%room))) || (emp==(i*j))) {
		printf("FANCY");
	}
	else {
		printf("NOT FANCY");
	}
}