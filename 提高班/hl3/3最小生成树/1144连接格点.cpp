#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 2 * N * N;

struct Edge
{
    int a, b, w;
}edge[M];

int n, m;
int p[N * N];
int ids[N][N];
int cnt;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void get_edges()
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dw[4] = {1, 2, 1, 2};

    for (int z = 0; z < 2; z ++ )  //两重循环，先做竖向的边z==0，再做横向的边z==1
        for (int i = 1; i <= n; i ++ )                                                                                                                                                                              
            for (int j = 1; j <= m; j ++ )
                for (int u = 0; u < 4; u ++ )  //枚举四个方向
                    if (u % 2 == z)  //z==0时 u%2为0的方向被添加，z==1时 u%2为1的方向被添加
                    {
                        int x = i + dx[u], y = j + dy[u], w = dw[u];
                        if (x && x <= n && y && y <= m)
                        {
                            int a = ids[i][j], b = ids[x][y];
                            if (a < b) edge[cnt ++ ] = {a, b, w};
                        }
                    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 1, t = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ , t ++ )
            ids[i][j] = t;
    
    for (int i = 1; i <= n * m; i ++ ) p[i] = i;
    
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
    {
        int a = ids[x1][y1], b = ids[x2][y2];
        int pa = find(a), pb = find(b);
        p[pa] = pb;
    }
    
    get_edges();
    
    int res = 0;
    for (int i = 0; i < cnt; i ++ )
    {
        auto e = edge[i];
        int pa = find(e.a), pb = find(e.b), w = e.w;
        if (pa != pb)
        {
            p[pa] = pb;
            res += w;
        }
    }
    
    cout << res << endl;
    return 0;
}