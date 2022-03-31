#include <stdio.h>
#include <string.h>

const long long MOD = 1e9 + 7;

char s[1000005];
int n;

long long modpow(long long a, long long x)
{
  if(x == 0)
    return 1LL;
  if(x == 1)
    return a;
  long long ret = modpow(a, x / 2);
  ret = (ret * ret) % MOD;
  if(x % 2)
    ret = (ret * a) % MOD;
  return ret;
}

int main()
{
  scanf("%s", s);
  n = strlen(s);
  int cnt = 0;
  int numA = 0, numB = 0;
  for(int a = 0; a < n; a++)
  {
    if(s[a] == 'a')
      numA++;
    else
      numB++;
    if(numA == numB)
      cnt++;
  }
  if(numA != numB)
  {
    printf("%d\n", 0);
    return 0;
  }
  long long ans = modpow(2, cnt - 1);
  printf("%lld\n", ans);
  return 0;
}

/* solve(i, j) --> number of solutions when we are considering the substring 
 * from i to j
 *
 * (i, j) --> (i, j + 1)
 * (i, j) --> (j + 1, j + 1)
 *
