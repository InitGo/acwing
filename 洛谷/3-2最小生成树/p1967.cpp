#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 50010, INF = 0x3f3f3f3f;

int n, m, q;
int p[N];
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int fa[N][15], depth[N], dist[N][15];
bool st[N];  

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &t) const
    {
        return w > t.w;
    }
}edge[M];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruskal_build()
{
    sort(edge, edge + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            add(a, b, w), add(b, a, w);
            p[pa] = pb;
        }
    }
}

void bfs() 
{
    //memset(dist, 0x3f, sizeof dist); 这里不初始化也能ac

    queue<int> q;
    for (int i = 1; i <= n; i ++ )  //每个连通块都入队列，本题只把1入队列也ac
    {
        if (!st[find(i)])
        {
            st[find(i)] = true;
            depth[i] = 1;
            q.push(i);
        }
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!depth[j])
            {
                depth[j] = depth[t] + 1;
                q.push(j);
                
                fa[j][0] = t;
                dist[j][0] = w[i];
                for (int k = 1; k <= 14; k ++ )
                {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    dist[j][k] = min(dist[j][k - 1], dist[anc][k - 1]);
                }
            }
        }
    }
}

int lca(int a, int b)
{   
    if (find(a) != find(b)) return -1;
    
    int ans = INF;
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 14; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
        {
            ans = min(ans, dist[a][k]);
            a = fa[a][k];
        }
    if (a != b)
    {
        for (int k = 14; k >= 0; k -- )
        {
            if (fa[a][k] != fa[b][k])  //注意这里第一段用depth，第二段直接用fa比
            {
                ans = min(ans, dist[a][k]);
                ans = min(ans, dist[b][k]);
                a = fa[a][k];
                b = fa[b][k];
            }
        }
        ans = min(ans, dist[a][0]);
        ans = min(ans, dist[b][0]);
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }
    
    kruskal_build();
    bfs();

    cin >> q;
    while (q -- )
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}