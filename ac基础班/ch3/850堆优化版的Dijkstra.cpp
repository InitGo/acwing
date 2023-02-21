//https://www.acwing.com/activity/content/problem/content/919/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];//！！！易错点：明确st的含义：是已经找到最短路径的点的集合，不是heap中点的的集合

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
 
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    //为什么这里不需要st[1] = true;
    //在for中包含了，因为1需要打完标记以后再更新其他点的距离
    

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        //找的是不在s中的距离最近的点，如果已经在s中，continue找下一个
        if (st[ver]) continue;//！！！这里易错
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i]) //权重w的下标是idx，而不是e[idx];
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}