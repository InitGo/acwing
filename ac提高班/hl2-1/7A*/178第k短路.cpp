#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int N = 1010, M = 20010;

int n, m;
int S, T, K;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, T});
    
    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;
    
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = rh[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar()
{
    if (dist[S] == 0x3f3f3f3f) return -1;  //特判一下S和T是否连通，如果不连通，没有最短路
    
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S] + 0, {0, S}});  //{估价距离 + 真实距离，{真实距离，点的编号}}
    
    int cnt = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second.second, distance = t.second.first;  //ver是点的编号，distance是ver点到T的真实距离
        
        if (ver == T) cnt ++ ;  //如果ver点是T了，T第cnt次出队，distance是第cnt短路
        if (cnt == K) return distance;  //如果已经求到了第K短路，直接返回distance
        
        for (int i = h[ver]; ~i; i = ne[i])  //扩展
        {
            int j = e[i];
            heap.push({dist[j] + distance + w[i], {distance + w[i], j}});  //估价距离是dist[j]， 真实距离是distance + w[i]
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    cin >> S >> T >> K;
    if (S == T) K ++ ;  //每条最短路中至少要包含一条边。如果起点和终点重合，则计算K+1短路
    
    dijkstra();
    
    cout << astar() << endl;
    
    return 0;
}