#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 210;

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &T) const
    {
        return w < T.w;
    }
}edge[M];

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    int total = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
        total += c;
    }
    
    sort(edge, edge + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    int res = 0;
    for (int i = 0; i < m; i ++ )
    {
        auto e = edge[i];
        int a = e.a, b = e.b, w = e.w;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            p[pa] = pb;
            res += w;
        }
    }
    
    cout << total - res << endl;
    
    return 0;
}