#include <bits/stdc++.h>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n;
int g[N][N], dist[N];
bool st[N];

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 0; j < n; j ++ )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        if (i && dist[t] == INF) return -1;
        
        st[t] = true;
        if (i) res += dist[t];
        
        for (int j = 0; j < n; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> g[i][j];
    
    cout << prim() << endl;
    
    return 0;
}