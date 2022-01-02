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
	int flag=0, maxNum=0, minNum=100;
	long int stdNo, i=0;

	scanf("%ld",&stdNo);

	long int marks[stdNo];
	
	flag = readMarks(marks, stdNo);

	for (i=0;i<stdNo;i++){
		if (marks[i] > maxNum){
			maxNum = marks[i];
		}
		if (marks[i] < minNum){
			minNum = marks[i];
		}
	}

	if (flag==0){
		printf("%d ", maxNum);
		printf("%d", minNum);
	}
}