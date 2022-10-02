#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int m, n;
int g[N][N], level[N];
int dist[N];
bool st[N];

int dijkstra(int l, int r)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    dist[0] = 0;
    
    for (int i = 0; i <= n; i ++ )
    {
        int t = -1;
        for (int j = 0; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        st[t] = true;
        
        for (int j = 0; j <= n; j ++ )
            if (level[j] >= l && level[j] <= r)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    return dist[1];
}

int main()
{
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i <= n; i ++ ) g[1][1] = 0;
    
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        g[0][i] = min(g[0][i], price);
        
        while (cnt -- )
        {
            int id, t_price;
            cin >> id >> t_price;
            g[id][i] = min(g[id][i], t_price);
        }
    }
    
    level[0] = level[1];
    
    int res = INF;
    for (int l = level[1] - m; l <= level[1]; l ++ )
        res = min(res, dijkstra(l, l + m));
    
    cout << res << endl;
    
    return 0;
}