#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, K;
int p[N];

struct Edge
{
    int a, b, w;
    bool operator< (const Edge &t) const
    {
        return w > t.w;
    }
}e[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m >> K;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }

    sort(e, e + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int ans = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        if (cnt >= K) break;
        int pa = find(e[i].a), pb = find(e[i].b), w = e[i].w;
        if (pa != pb)
        {
            p[pa] = pb;
            ans += w;
            cnt ++ ;
        }
    }

    cout << ans << endl;

    return 0;
}