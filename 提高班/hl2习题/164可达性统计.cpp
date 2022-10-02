#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

int n, m;
bitset<N> f[N];
int d[N], seq[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        if (d[i] == 0) seq[ ++ tt] = i;
    
    while (hh <= tt)
    {
        int t = seq[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            d[j] -- ;
            if (d[j] == 0) seq[ ++ tt] = j;
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++ ;
    }
    
    topsort();
    
    for (int i = n - 1; ~i; i -- )
    {
        int j = seq[i];
        f[j][j] = 1;
        for (int k = h[j]; ~k; k = ne[k])
            f[j] |= f[e[k]];
    }
    
    for (int i = 1; i <= n; i ++ )
        cout << f[i].count() << endl;
    return 0;
}