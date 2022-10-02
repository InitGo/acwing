#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e18 + 10;
const int mod = 1e9 + 7;

int a, b, n, k;
int ans = 0;
ll path[2];
ll f[2][N];

bool check(ll i, int a, ll j, int b, int k)
{
    int res1 = 1, res2 = 1;
    while (a)
    {
        if (a & 1) res1 = res1 * i % k;
        i = i * i % k;
        a >>= 1;
    }

    while (b)
    {
        if (b & 1) res2 = res2 * j % k;
        j = j * j % k;
        b >>= 1;
    }

    int res = ((res1 % k) + (res2 % k)) % k;

    return !res;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        ans = 0;
        cin >> a >> b >> n >> k;
        
        // 过set1 的写法
        // for (int i = 1; i <= n; i ++ )
        //     for (int j = 1; j <= n; j ++ )
        //     {
        //         if (i == j) continue;
        //         if (check(i, a, j, b, k)) ans = (ans + 1) % mod;
        //     }
        // printf("Case #%d: %d\n", C, ans);
        
        memset(f, 0, sizeof f);
        for (ll i = 2; i <= n; i ++ )
            for (ll j = 2; j <= n; j ++ )
            {
                if (i == j) continue;
                f[i & 1][j] = f[i - 1 & 1][j] + f[i & 1][j - 1] - f[i - 1 & 1][j - 1] + check(i, a, j, b, k);
            }
        printf("Case #%d: %lld\n", C, f[n & 1][n]);
    }
    return 0;
}