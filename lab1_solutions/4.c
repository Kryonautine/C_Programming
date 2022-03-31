#include <stdlib.h>
typedef long long LL;
#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#include <math.h>


int main()
{
    LL n, i, j, k, t, temp, tc;
    scanf("%lld", &n);
    LL lim = sqrt(n) + 3;
    LL minima = n + 2;
    for (i = 1; i <= lim; i++)
    {
        if (n % i == 0)
        {
            LL check=i - 1 + (n / i) - 1;
            // if(check==minima)
            // {
            //     assert(false);
            // }
            minima = MIN(minima,check );
        }
    }
    printf("%lld", minima);

    return 0;
}

