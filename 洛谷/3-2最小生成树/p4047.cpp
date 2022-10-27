#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 1010, M = N * N;

int n, m, k;
int p[N];
PII pos[N];

struct Edge
{
    int a, b;
    double w;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
}e[M];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

double get_dist(int i, int j)
{
    int dx = pos[i].x - pos[j].x;
    int dy = pos[i].y - pos[j].y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) cin >> pos[i].x >> pos[i].y;

    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            e[m ++ ] = {i, j, get_dist(i, j)};

    sort(e, e + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int idx = 0;
    int cnt = n;
    for (int i = 0; i < m; i ++ )
    {
        if (cnt <= k) break;
        int pa = find(e[i].a), pb = find(e[i].b);
        double w = e[i].w;
        if (pa != pb)
        {
            p[pa] = pb;
            idx = i;
            cnt -- ;
        }
    }

    double ans = 0;
    for (int i = idx + 1; i < m; i ++ )
    {
        int pa = find(e[i].a), pb = find(e[i].b);
        double w = e[i].w;
        if (pa != pb)
        {
            ans = e[i].w;
            break;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}