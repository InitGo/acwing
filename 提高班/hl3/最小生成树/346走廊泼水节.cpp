#include <bits/stdc++.h>

using namespace std;

const int N = 6010;

int n;
int p[N], cnt[N];

struct Edge
{
    int a, b, w;
    bool operator< (const Edge& t) const 
    {
        return w < t.w;
    }
}e[N];

int find(int x) 
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n - 1; i ++ )
        {
            int a, b, w;
            cin >> a >> b >> w;
            e[i] = {a, b, w};
        }
        
        for (int i = 1; i <= n; i ++ ) p[i] = i, cnt[i] = 1;
        
        sort(e, e + n - 1);
        
        int res = 0;
        for (int i = 0; i < n - 1; i ++ )
        {
            int pa = find(e[i].a), pb = find(e[i].b);
            if (pa != pb)
            {
                res += (cnt[pa] * cnt[pb] - 1) * (e[i].w + 1);
                cnt[pb] += cnt[pa];
                p[pa] = pb;
            }
        }
        
        cout << res << endl;
    }
    return 0;
}