#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 2510, M = 12410;

int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, S});
    
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, d = t.first;
        
        if (st[ver]) continue;
        
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > d + w[i])
            {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
        
    }
    return dist[T];
}

int main()
{
    cin >> n >> m >> S >> T;
    
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}