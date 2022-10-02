//https://www.acwing.com/activity/content/problem/content/924/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];


int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        //找到集合外距离最小的点
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF; 
        //dist初始化为INF，第一次迭代找到的肯定是INF
        //如果不是第一次迭代，并且集合外最小距离是INF
        //表明 当前所有点距离集合的距离都是INF 当前的图是不连通的
        //不存在最小生成树，直接返回INF

        //否则，只要不是第一条边（第一个点不带边进来），就把这条边加到答案里面去
        //dist[t] 表示当前这个点与集合里某个点之间的边的长度【这个点到集合的距离】
        //也是最小生成树的树边
        if (i) res += dist[t];
        st[t] = true;

        //先把dist[t]加入res，再来更新其他边
        //如果存在负环，选中以后会把自己也更新，所以先累加，再更新，顺序不能变
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
        //!!!注意这里dist含义是点到集合的距离，注意更新项
    }

    return res;
}


int main()
{
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) puts("impossible");
    else printf("%d\n", t);

    return 0;
}
