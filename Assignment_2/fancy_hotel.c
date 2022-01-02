#include <stdio.h>

int main(void) {
	long int floor, room, mal=0, fem=0, emp=0, i=0, j=0;

	scanf("%ld", &floor);
	scanf("%ld", &room);

	int hotel[floor][room];

	for (i=0;i<floor;i++) {
		for (j=0;j<room;j++) {
			scanf("%d", &hotel[i][j]);
		}
	}
}