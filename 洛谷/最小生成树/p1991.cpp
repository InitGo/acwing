#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> PII;

#define x first
#define y second

const int N = 510, M = N * N;

int k, n;
PII pos[N];
int p[N];

struct Edge
{
    int a, b;
    double w;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
}e[M];
int e_cnt;

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

double get_dist(int i, int j)
{
    double dx = pos[i].x - pos[j].x;
    double dy = pos[i].y - pos[j].y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= n; i ++ ) cin >> pos[i].x >> pos[i].y;

    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            e[e_cnt ++ ] = {i, j, get_dist(i, j)};
    
    sort(e, e + e_cnt);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int cnt = n;
    double res = 0;
    for (int i = 0; i < e_cnt; i ++ )
    {
        if (cnt <= k) break;
        int pa = find(e[i].a), pb = find(e[i].b);
        double w = e[i]. w;

        if (pa != pb)
        {
            p[pa] = pb;
            res = w;
            cnt -- ;
        }
    }

    printf("%.2lf\n", res);

    return 0;
}