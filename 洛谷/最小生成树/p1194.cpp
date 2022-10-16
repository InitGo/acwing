#include <bits/stdc++.h>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < m + 1; i ++ )
    {
        int t = -1;
        for (int j = 0; j <= m; j ++ )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        if (i && dist[t] == INF) return -1;
        st[t] = true;
        if (i) res += dist[t];

        for (int j = 0; j <= m; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;   
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            int x;
            cin >> x;
            if (!x) g[i][j] = INF;
            else g[i][j] = x;
        }
    
    for (int i = 1; i <= m; i ++ ) g[0][i] = n, g[i][0] = n;

    cout << prim() << endl;
    return 0;
}