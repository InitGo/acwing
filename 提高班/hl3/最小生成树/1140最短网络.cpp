#include <bits/stdc++.h>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        if (i && st[t] == INF) return INF;
        st[t] = true;
        if (i) res += dist[t];
        
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            int x;
            cin >> x;
            g[i][j] = g[j][i] = min(g[i][j], x);
        }
    
    cout << prim() << endl;
    return 0;
}