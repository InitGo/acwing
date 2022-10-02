#include <bits/stdc++.h>

using namespace std;

const int N = 410, INF = 0x3f3f3f3f; //要开2倍空间，实际上N = 2 * 200

int n;
int w[N], s[N];
int f[N][N], g[N][N]; //分别计算min和max

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
        w[i + n] = w[i]; //后半段与前半段完全相同
    }
    
    for (int i = 1; i <= 2 * n; i ++ ) s[i] = s[i - 1] + w[i]; //计算前缀和，注意是整个链2n长度的
    
    memset(f, 0x3f, sizeof f);
    memset(g, 0xcf, sizeof g);
    
    for (int len = 1; len <= n; len ++ )
        for (int i = 1; i + len - 1 <= 2 * n; i ++ )
        {
            int l = i, r = i + len - 1;
            if (len == 1) f[l][r] = g[l][r] = 0; //如果长度为1，开销都是0
            for (int k = l; k < r; k ++ )
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    
    int minv = INF, maxv = -INF;
    for (int i = 1; i + n - 1 <= 2 * n; i ++ ) //在长度为n的区间中计算最值 for (int i = 1; i - 1 <= n; i ++ )
    {
        minv = min(minv, f[i][i + n - 1]);
        maxv = max(maxv, g[i][i + n - 1]);
    }
    cout << minv << endl << maxv << endl;
    return 0;
}