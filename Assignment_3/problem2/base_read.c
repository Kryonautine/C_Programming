#include <stdio.h>

int main(void) {
	int ele, i;
	scanf("%d", &ele);
	long int polyarray[ele];

	for (i=0;i<ele;i++) {
		scanf("%ld", &polyarray[i]);
	}
}