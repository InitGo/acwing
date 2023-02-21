#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = N * N;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0] = 0;
    deque<PII> q;
    q.push_back({0, 0});

    char cs[] = "\\/\\/";
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1}; //可以到达的位置
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1}; //所依赖的路径状态

    while (q.size())
    {
        PII t = q.front();
        q.pop_front();

        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true; //出队列的时候标记 为什么？
        //必须在出队时才知道每个点最终的最小值，与堆优化的dijkstra一样
        //把双端队列当作dijkstra的小根堆来用

        for (int i = 0; i < 4; i ++ )
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;

            int ca = t.x + ix[i], cb = t.y + iy[i];
            int d = dist[t.x][t.y] + (g[ca][cb] != cs[i]);

            if (d < dist[a][b]) //更新距离
            {
                dist[a][b] = d;

                //判断插入队头还是队尾， 插入队列
                if (g[ca][cb] != cs[i]) q.push_back({a, b});
                else q.push_front({a, b});
            }
        }
    }

    return dist[n][m];
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

        int t = bfs();

        if (t == 0x3f3f3f3f) puts("NO SOLUTION");
        else printf("%d\n", t);
    }

    return 0;
}