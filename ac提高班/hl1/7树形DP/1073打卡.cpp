#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e4 + 10, M = 2 * N, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], ne[M], w[M], idx;
int d1[N], d2[N], p1[N], p2[N], up[N];
bool is_leaf[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs_d(int u, int mother)
{
    d1[u] = d2[u] = -INF;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == mother) continue;
        
        int d = dfs_d(j, u) + w[i];
        if (d > d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p2[u] = p1[u], p1[u] = j;
        }
        else if (d > d2[u]) d2[u] = d, p2[u] = j;
    }
    
    if (d1[u] == -INF)
    {
        is_leaf[u] = true;
        d1[u] = 0;
    }
    
    return d1[u];
}

void dfs_u(int u, int mother)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == mother) continue;
        
        if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(up[u], d1[u]) + w[i];
        
        dfs_u(j, u);
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    dfs_d(1, -1);
    dfs_u(1, -1);
    
    int res = d1[1];
    for (int i = 2; i <= n; i ++ )
        if (is_leaf[i]) res = min(res, up[i]);
        else res = min(res, max(d1[i], up[i]));
    
    cout << res << endl;
    return 0;
}