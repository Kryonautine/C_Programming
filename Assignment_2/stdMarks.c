#include <stdio.h>

void readMarks(int* marks[],int stdN){
	int i;

	for (i=0;i<stdN;i++){
		scanf("Enter marks of student %d : ",&marks[i]);
	}

}

int main(void){
	int stdNo;

	printf("Enter number of students : ");
	scanf("%d",&stdNo);

	int marks[stdNo];
	
	readMarks(&marks[stdNo], stdN);


	for (i=0;i<stdN;i++){
		printf("Enter marks of student %d : ",&marks[i]);
	}
}