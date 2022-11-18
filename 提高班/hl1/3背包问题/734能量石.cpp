#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n;
struct Stone
{
    int s, e, l;
    bool operator< (const Stone &t) const
    {
        return s * t.l < t.s * l;
    }
}stones[N];

int f[N][M];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        int m = 0;
        for (int i = 1; i <= n; i ++ )
        {
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
            m += s; //m是消耗的总体积最大值
        }

        sort(stones + 1, stones + 1 + n);  //按照 si * li+1 < si+1 * li 排序
        
        for (int i = 1; i <= n; i ++ ) //枚举物品
            for (int j = 0; j <= m; j ++ ) //枚举体积 没有压缩空间，顺序任意
            {
                f[i][j] = f[i - 1][j];
                if (j >= stones[i].s)
                {
                    int s = stones[i].s, e = stones[i].e, l = stones[i].l;
                    f[i][j] = max(f[i][j], f[i - 1][j - s] + max(0, e - l * (j - s)));
                }
            }

        int res = 0;
        for (int i = 0; i <= m; i ++ ) res = max(res, f[n][i]);

        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}