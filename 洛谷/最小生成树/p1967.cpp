#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 50010, INF = 0x3f3f3f3f;

int n, m, q;
int p[N], dist[N];
int h[N], e[M * 2], ne[M * 2], w[M * 2], idx;
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

int dfs(int a, int b)
{
    st[a] = true;
    if (a == b) return INF;
    int t = INF;
    for (int i = h[a]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            t = min(t, w[i] + dfs(j, b));
        }
    }
    return t;
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

    sort(edge, edge + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    for (int i = 0; i < m; i ++ )
    {
        auto t = edge[i];
        int a = t.a, b = t.b, w = t.w;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            add(a, b, w), add(b, a, w);
            p[pa] = pb;
        }
    }

    cin >> q;
    while (q -- )
    {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb) cout << -1 << endl;
        else 
        {
            memset(st, 0, sizeof st);
            cout << dfs(a, b) << endl;
        }
    }
    return 0;
}