#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 510, M = 10010;

struct Edge
{
    int a, b;
    double w;
    bool operator< (const Edge& t) const
    {
        return w < t.w;
    }
}edge[N * N];

int n, k, cnt;
PII pos[N];
int p[N], f[N];
bool st[N];

double get_dist(int i, int j)
{
    int dx = pos[i].x - pos[j].x;
    int dy = pos[i].y - pos[j].y;
    return sqrt(dx * dx + dy * dy);
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool check(double d)
{
    memcpy(p, f, sizeof f);
    for (int i = 0; i < cnt; i ++ )
    {
        auto e = edge[i];
        int pa = find(e.a), pb = find(e.b);
        if (pa != pb && e.w <= d)
            p[pa] = pb;
    }
    
    int block_cnt = 0;
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i ++ )
    {
        if (!st[i])
        {
            block_cnt ++ ;
            st[i] = true;
            int p = find(i);
            for (int j = 0; j < n; j ++ )
                if (!st[j] && find(j) == p)
                    st[j] = true;
        }
    }
    
    if (block_cnt == 1) return true;
    return block_cnt <= k;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) f[i] = i;
    for (int i = 0; i < n; i ++ ) cin >> pos[i].x >> pos[i].y;
    
    for (int i = 0; i < n; i ++ )
        for (int j = i + 1; j < n; j ++ )
            edge[cnt ++ ] = {i, j, get_dist(i, j)};
    
    sort(edge, edge + cnt);
    
    double l = 0, r = 15000;
    while (r - l > 1e-4)
    {
        double mid = (l + r) / 2.0;
        if (check(mid)) r = mid;
        else l = mid;
    }
    
    printf("%.2lf\n", l);
    
    return 0;        
}