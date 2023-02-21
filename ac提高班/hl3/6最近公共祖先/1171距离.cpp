#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 2 * N;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][15], depth[N], dist[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    
    while (q.size()) 
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                q.push(j);
                depth[j] = depth[t] + 1;
                dist[j] = dist[t] + w[i];
                f[j][0] = t;
                for (int k = 1; k <= 14; k ++ )
                    f[j][k] = f[f[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    
    for (int k = 14; k >= 0; k -- )
        if (depth[f[a][k]] >= depth[b])
            a = f[a][k];
    
    if (a == b) return a;
    
    for (int k = 14; k >= 0; k -- )
        if (f[a][k] != f[b][k])
        {
            a = f[a][k];
            b = f[b][k];
        }
    return f[a][0];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    bfs();
    
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        cout << dist[a] + dist[b] - 2 * dist[p] << endl;
    }
    
    return 0;
}