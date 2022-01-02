#include <stdio.h>
#include <math.h>

int readMarks(long int marks[],long int stdN){
	int flag=0;
	long int i=0;

	for (i=0;i<stdN;i++){
		scanf("%ld", &marks[i]);
		if ((marks[i]<0) || (marks[i]>100)){
			printf("INVALID INPUT\n");
			flag++;
			break;
		}
	}

	return(flag);
}

int main(void){
	int pass, flag=0;
	long int stdNo, i=0, pass_no=0;
	double pass_percent;

	scanf("%ld",&stdNo);
	scanf("%d",&pass);

	long int marks[stdNo];
	
	flag = readMarks(marks, stdNo);

	for (i=0;i<stdNo;i++){
		if (marks[i]>= pass){
			pass_no++;
		}
	}

	if (flag==0){
		//pass_percent = (100.0/stdNo) * pass_no;
		pass_percent = (double) ((100.0* pass_no) / stdNo); 
		printf("%2.6f\n", pass_percent);
	}
}