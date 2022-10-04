#include <bits/stdc++.h>

using namespace std;

const int N = 310, M = 8010;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &t) const 
    {
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
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
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
            res = w;
        }
    }
    
    printf("%d %d\n", n - 1, res);
    return 0;
}