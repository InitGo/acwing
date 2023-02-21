#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 400010;

int n, m, q;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int limit)
{
    int res = 1;
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (w[i] >= limit && !st[j]) res += dfs(j, limit);
    }
    return res;
}

int main()
{
    cin >> n >> m >> q;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    while (q -- )
    {
        int a, b;
        cin >> a >> b;
        memset(st, 0, sizeof st);
        cout << dfs(a, b) << endl;
    }
    return 0;
}