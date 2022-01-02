#include <stdio.h>

int main(void)
{

	long int nthNum, check=0, kthNum, i=3, n=1, k=2,Noti=2;

	scanf("%ld",&nthNum);
	scanf("%ld",&kthNum);

	if (kthNum==1)
	{
		if (nthNum==1)
		{
			printf("1");
			check++;
		}
	}

	if (kthNum==2)
	{
		if (nthNum==1)
		{
			printf("2");
			check++;
		}
	}

	while (check==0){

		while (Noti <i)
		{
			if (i% Noti == 0)
			{
				k++;
			}
			Noti++;
		}
		Noti=2;
		
		if (kthNum==k)
		{
			if (n==nthNum)
			{
				printf("%ld", i);
				check++;
			}
			n++;
		}
		k=2;
		i++;
	}
}