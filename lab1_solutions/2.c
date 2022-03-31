#include <stdio.h>

int realpart[1000][1000];
int impart[1000][1000];
int n;

int checkHermitian()
{
  for(int a = 0; a < n; a++)
    for(int b = 0; b < n; b++)
      if(realpart[a][b] != realpart[b][a] || impart[a][b] != -impart[b][a])
        return 0;
  return 1;
}

int checkCircular()
{
  for(int a = 1; a < n; a++)
  {
    if(realpart[a][0] != realpart[a - 1][n - 1] || impart[a][0] != impart[a - 1][n - 1])
      return 0;
    for(int b = 1; b < n; b++)
      if(realpart[a][b] != realpart[a - 1][b - 1] || impart[a][b] != impart[a - 1][b - 1])
        return 0;
  }
  return 1;
}

int main()
{
  scanf("%d", &n);
  for(int a = 0; a < n; a++)
    for(int b = 0; b < n; b++)
      scanf("%d%d", &realpart[a][b], &impart[a][b]);
  if(checkHermitian() && checkCircular())
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

