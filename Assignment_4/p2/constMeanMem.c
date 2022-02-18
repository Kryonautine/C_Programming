#include <stdio.h>

int main(void) {
	int num;
	double mean, buffer, sum=0;

	printf("Enter number of elements :");
	scanf("%d", &num);
	for (int i=0; i<num;i++) {
		scanf("%f", &buffer);
		sum += buffer;
	}
	mean = sum/num;
	printf("Mean = %f\n", mean);
}
// Need to read input format and other things.