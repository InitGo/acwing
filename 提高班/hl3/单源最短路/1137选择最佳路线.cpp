#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

int n, m, T;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], q[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa()
{
    int scnt;
    scanf("%d", &scnt);

    memset(dist, 0x3f, sizeof dist);

    int hh = 0, tt = 0;
    while (scnt -- )
    {
        int u;
        scanf("%d", &u);
        dist[u] = 0;
        q[tt ++ ] = u;
        st[u] = true;
    }

    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;

        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q[tt ++ ] = j;
                    if (tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &T) != -1)
    {
        memset(h, -1, sizeof h);
        idx = 0;

        while (m -- )
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }

        spfa();

        if (dist[T] == INF) dist[T] = -1;
        printf("%d\n", dist[T]);
    }

    return 0;
}