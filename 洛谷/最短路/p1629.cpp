#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

#define x first
#define y second

const int N = 1010, M = 200010;

int n, m, S;
int hl[N], hr[N], e[M], w[M], ne[M], idx;
int dist1[N], dist2[N];
bool st[N];

void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra(int h[], int dist[])
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist1);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({0, 1});

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
    cin >> n >> m;
    memset(hl, -1, sizeof hl);
    memset(hr, -1, sizeof hr);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(hl, a, b, c);
        add(hr, b, a, c);
    }

    dijkstra(hl, dist1);
    dijkstra(hr, dist2);

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        res += dist1[i] + dist2[i];
    cout << res << endl;
    return 0;
}