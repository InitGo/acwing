#include <bits/stdc++.h>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int p[N];

struct Edge
{
    int p, a, b, w;
    bool operator< (const Edge &t) const
    {
        if (p != t.p) return p < t.p;
        return w < t.w;
    }
}edge[M];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int p, a, b, w;
        cin >> p >> a >> b >> w;
        edge[i] = {p, a, b, w};
    }
    
    sort(edge, edge + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    int res = 0;
    for (int i = 0; i < m; i ++ )
    {
        auto e = edge[i];
        int pa = find(e.a), pb = find(e.b), w = e.w;
        bool is_added = false;
        if (pa != pb)
        {
            p[pa] = pb;
            res += w;
            is_added = true;
        }
        if (!is_added && e.p == 1) res += w;
    }
    
    cout << res << endl;
    
    return 0;
}