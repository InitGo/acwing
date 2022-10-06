#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 5e4 + 10, M = 2e5 + 10;

int n, m;
int source[6];
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int g[6][6];
int path[6];
int ans = 0x3f3f3f3f;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa(int s, int index)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    st[s] = true;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < 6; i ++ )
    {
        int j = source[i];
        g[i][index] = g[index][i] = min(g[index][i], dist[j]);
    }
    return;
}

void dfs(int u)
{
    if (u == 5)
    {
        for (int i = 0; i < 5; i ++ ) cout << path[i] << ' ';
        cout << "  ";        
        int res = g[0][path[0]];
        for (int i = 0; i < 4; i ++ )
            res += g[path[i]][path[i + 1]];
        cout << "ans : " << ans << "   " << "res : " << res << endl;
        ans = min(ans, res);
        // for (int i = 0; i < 5; i ++ ) cout << path[i] << ' ';
        // cout << endl;
        return;
    }
    
    for (int i = 1; i < 6; i ++ )
    {
        if (st[i]) continue;
        
        st[i] = true;
        path[u] = i; //source的第i个位置上的数
        dfs(u + 1);
        st[i] = false;
    }    
    
}

int main()
{
    cin >> n >> m;
    
    source[0] = 1;
    for (int i = 1; i < 6; i ++ ) cin >> source[i];
    
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < 6; i ++ )
        spfa(source[i], i);
    
    // for (int i = 0; i < 6; i ++ )
    // {
    //     for (int j = 0; j < 6; j ++ )
    //         cout << g[i][j] << ' ';
    //     cout << endl;
    // }
    
    memset(st, 0, sizeof st);
    dfs(0);
    cout << ans << endl;
    
    return 0;
}