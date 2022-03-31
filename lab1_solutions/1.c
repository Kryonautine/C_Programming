#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main()
{
	char *o, e[100002], sh[100002];
  o = (char*) malloc(100002 * sizeof(char));
	int T,i,a,b,j,k,x;
	char t1, t2;
	
	scanf("%d",&T);

  for(i=0;i<T;i++)
	{
		char arr[26]={0};
		scanf("%d",&k);
    scanf("%c",&t1);
    scanf("%[^\n]",o);
		scanf("%c",&t2);
		scanf("%[^\n]",e);
    int siz = 100002;
		for(x=0;x<strlen(o);x++)
		{
			if(o[x]==' '){
				sh[x]=' ';
				continue;
			}
			int d = (o[x] + k - 'a')%26 + 'a';
			sh[x] = (char)(d);
		}

		a = strlen(o);
		b = strlen(e);

		if(a!=b)
			printf("False\n");

		else
		{
			for(j=0;j<a;j++)
				arr[sh[j]-'a'] += 1;
			for(j=0;j<b;j++)
				arr[e[j]-'a'] -= 1;
			int c = 0;

			for(j=0;j<26;j++)
				if(arr[j]==0)
					c++;
			

			if(c==26)
				printf("True\n");
			else
				printf("False\n");
		}
	}
	return 0;
}

