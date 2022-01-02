#include <stdio.h>
#include <math.h>

int readMarks(long int marks[],long int stdN){
	int flag=0;
	long int i=0;

	for (i=0;i<stdN;i++){
		printf("Enter marks of student %ld : ",i+1);
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
	int pass, flag=0;
	long int stdNo, i=0, pass_no=0, sum=0;
	float stdDevia=0, variance=0, stdSum=0, mean=0;

	printf("Enter number of students : ");
	scanf("%ld",&stdNo);

	printf("Enter Pass Marks : ");
	scanf("%d",&pass);

	long int marks[stdNo];
	
	flag = readMarks(marks, stdNo);

	for (i=0;i<stdNo;i++){
		if (marks[i]>= pass){
			pass_no++;
		}
	}

	for (i=0;i<stdNo;i++){
		sum += marks[i];
	}

	mean = (float) sum/stdNo;

	for (i=0;i<stdNo;i++){
		stdSum += powf((marks[i]-mean), 2);
	}

	variance = stdSum/stdNo;

	stdDevia = sqrt(variance);

	if (flag==0){

		printf("Pass Percentage is : %f %%\n", (100.0/stdNo) * pass_no);
		printf("Mean is : %f \n", mean);
		printf("Variance is : %f \n", variance);
		printf("Standard Deviation is : %f \n", stdDevia);
	}
}