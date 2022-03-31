#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define fr(i, n) for (i = 0; i < n; i++)
#define rep(i, n) for (i = 1; i <= n; i++)
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>
#define intCeil(a, b) ((a) + (b)-1) / (b)

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; // trick to explore an implicit 2D grid
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // S,SE,E,NE,N,NW,W,SW neighbors  //GO FOR EVEN FOR 4 moves

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

LL POW(LL x, LL y)
{
    LL ans = 1;
    LL base = x;
    while (y)
    {
        if (y & 1)
        {
            ans *= base;
        }
        base = base * base;
        y = y >> 1;
    }
    return ans;
}

int main()
{
    fastinput;
    LL n, i, j, k, t, temp, tc;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(all(arr));
    cin >> k;
    for (i = 0; i < k; i++)
    {
        //cin >> t;
        int lb = 0, ub = n - 1;
        int pos1 = -1, pos2 = n;
        int left_idx;
        int right_idx;
        cin >> left_idx >> right_idx;

        t = right_idx;
        // first number >= L
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (arr[mid] <= t)
            {
                lb = mid + 1;
            }
            else
            {
                pos2 = mid;
                ub = mid - 1;
            }
        }

        t = left_idx;
        lb = 0, ub = n - 1;
        //<
        while (lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if (arr[mid] < t)
            {
                pos1 = mid;
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }

        cout << pos2 - pos1 - 1 << " ";
    }

    return 0;
}

