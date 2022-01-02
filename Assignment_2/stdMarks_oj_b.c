#include <stdio.h>
#include <math.h>

int readMarks(long int marks[],long int stdN){
	int flag=0;
	long int i=0;

	for (i=0;i<stdN;i++){
		scanf("%ld", &marks[i]);
		if ((marks[i]<0) || (marks[i]>100)){
			printf("INVALID INPUT");
			flag++;
			break;
		}
	}

	return(flag);
}

int main(void){
	int flag=0;
	long int stdNo, i=0, sum=0;
	double stdDevia=0, variance=0, stdSum=0, mean=0;

	scanf("%ld",&stdNo);

	long int marks[stdNo];
	
	flag = readMarks(marks, stdNo);

	for (i=0;i<stdNo;i++){
		sum += marks[i];
	}

	mean = (double) sum/stdNo;

	for (i=0;i<stdNo;i++){
		stdSum += pow((marks[i]-mean), 2);
	}

	variance = stdSum/stdNo;

	stdDevia = sqrtl(variance);

	if (flag==0){

		printf("%2.6f ", mean);
		printf("%2.6f ", variance);
		printf("%2.6f", stdDevia);
	}
}