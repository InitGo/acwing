#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], d[N][N];
int res = INF;

int main()
{
    cin >> n >> m;
    
    //邻接矩阵建图
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++ ) g[i][i] = 0;
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    //g数组存原始的边，d数组用来做floyd
    memcpy(d, g, sizeof g);
    for (int k = 1; k <= n; k ++ )
    {
        for (int i = 1; i < k; i ++ )  
            for (int j = i + 1; j < k; j ++ )
                res = min((long long)res, (long long)d[i][j] + g[j][k] + g[k][i]);
                //为什么这里会爆int？ 因为，两个g都可能是INF = 1e9，两个g相加就爆了

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    if (res == INF) cout << "No solution." << endl;
    else cout << res << endl;
    
    return 0;
}