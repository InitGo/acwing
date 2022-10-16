#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

const int N = 10010, M = 100010;
const LL INF = 1e20;

int n, m, b;
int h[N], e[M], w[M], ne[M], idx;
int price[N];
LL dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool check(int x)
{
    if (price[1] > x || price[n] > x) return false;
    
    memset(st, 0, sizeof st);
    for (int i = 2; i <= n; i ++ ) dist[i] = INF;

    priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
    dist[1] = 0;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, dis = t.first;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (price[j] > x) continue;

            if (dist[j] > dis + w[i])
            {
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n] <= b;
}

int main()
{
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i ++ ) cin >> price[i];

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (!check(r)) cout << "AFK" << endl;
    else cout << r << endl;
    return 0;
}