#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];

int main()
{
    cin >> n >> m;

    memset(f, -0x3f, sizeof f); //恰好：初始化为非法值：负无穷
    f[0] = 0;
    g[0] = 1; //什么都不装是一种方案 初始化为1

    for (int i = 0; i < n; i ++ )
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j -- )
        {
            int maxv = max(f[j], f[j - v] + w); //先求出maxv的值
            int s = 0;
            if (f[j] == maxv) s = g[j];
            if (f[j - v] + w == maxv) s = (s + g[j - v]) % mod;
            f[j] = maxv, g[j] = s;
        }
    }

    //先求出最大值
    int res = 0;
    for (int i = 1; i <= m; i ++ )
        res = max(res, f[i]);

    //再统计取得最大值的方案有多少个
    int sum = 0;
    for (int i = 0; i <= m; i ++ )
        if (f[i] == res)
            sum = (sum + g[i]) % mod;

    cout << sum << endl;

    return 0;
}