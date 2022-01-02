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
	long int stdNo, i=0, sum=0, sec1=0, sec2=0, sec3=0;
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

	for (i=0;i<stdNo;i++){
		if (((mean-(stdDevia*2)) <= marks[i]) && (marks[i] <= (mean+(stdDevia*2)))){
			if (((mean-stdDevia) <= marks[i]) && (marks[i] <= (mean+stdDevia))){
				sec1++;
			}
			sec2++;
		}
		else{
			sec3++;
		}
	}

	if (flag==0){
		printf("%ld ", sec1);
		printf("%ld ", sec2);
		printf("%ld\n", sec3);
	}
}