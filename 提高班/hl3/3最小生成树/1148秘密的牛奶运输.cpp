#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510, M = 10010;

int n, m;
struct Edge
{
    int a, b, w;
    bool is_tree;  //是否是树边
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
}edge[M];
int p[N];
int dist1[N][N], dist2[N][N];
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

//求最小生成树上的每个点到其他点的路径上的最大边和次大边
//u表示当前点，fa表示u的father点，
void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
    d1[u] = maxd1, d2[u] = maxd2;  //i->u的最大和次大
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            //处理当前点u的各个出边：u->j
            int td1 = maxd1, td2 = maxd2;  //没和w比较之前的最大边和次大边
            if (w[i] > td1) td2 = td1, td1 = w[i];  //同时更新最大和次大
            else if (w[i] < td1 && w[i] > td2) td2 = w[i];  //只更新次大
            //dfs下一个点
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);  //读入边
    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }

    sort(edge, edge + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    LL sum = 0;  //计算最小生成树的权值之和，同时把最小生成树建出来
    for (int i = 0; i < m; i ++ )
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            p[pa] = pb;
            sum += w;
            add(a, b, w), add(b, a, w);  //把最小生成树建出来
            edge[i].is_tree = true;  //这条边是树边，标记
        }
    }

    for (int i = 1; i <= n; i ++ ) dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);  //最大边，次大边

    LL res = 1e18;
    for (int i = 0; i < m; i ++ )
        if (!edge[i].is_tree)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            LL t;
            if (w > dist1[a][b])  //如果当前非树边大于最大边，可以直接替换
                t = sum + w - dist1[a][b];
            else if (w > dist2[a][b])  //如果当前非树边等于最大边，那么用最大边直接替换不符合严格次小生成树，所以用次大边替换
                t = sum + w - dist2[a][b];
            res = min(res, t);
        }

    cout << res << endl;

    return 0;
}