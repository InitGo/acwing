#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 100010, M = 2 * N;

int n, m, S;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[S] = 0;
    heap.push({0, S});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.y, dis = t.x;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dis + w[i])
            {
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m >> S;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    for (int i = 1; i <= n; i ++ )
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}