//本题卡输入和vector，用提交记录里的代码

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010, M = 300010, INF = 0x3f3f3f3f;

int n, m;
struct Edge
{
    int a, b, w;
    bool used;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
}edge[M];
int p[N];
int h[N], e[M], w[M], ne[M], idx;
int depth[N], fa[N][17], d1[N][17], d2[N][17];
int q[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

LL kruskal()
{
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    sort(edge, edge + m);
    LL res = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
        if (a != b)
        {
            p[a] = b;
            res += w;
            edge[i].used = true;
        }
    }

    return res;
}

void build()
{
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ )
        if (edge[i].used)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            add(a, b, w), add(b, a, w);
        }
}

//预处理4个数组
void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    q[0] = 1;
    int hh = 0, tt = 0;
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                
                fa[j][0] = t;
                d1[j][0] = w[i], d2[j][0] = -INF;  //只往上跳一步，没有次大边
                for (int k = 1; k <= 16; k ++ )
                {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    int distance[4] = {d1[j][k - 1], d2[j][k - 1], d1[anc][k - 1], d2[anc][k - 1]};
                    d1[j][k] = d2[j][k] = -INF;
                    for (int u = 0; u < 4; u ++ )
                    {
                        int t = distance[u];
                        if (t > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = t;
                        else if (t < d1[j][k] && t > d2[j][k]) d2[j][k] = t;
                    }
                }
            }
        }
    }
}

//做变换T(+w, -maxd)
int lca(int a, int b, int w)
{
    vector<int> distance;
    if (depth[a] < depth[b]) swap(a, b);

    //先让a跳到和b同层
    for (int k = 16; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
        {
            distance.push_back(d1[a][k]);  //跳这一段的最大边和次大边都加入缓存区
            distance.push_back(d2[a][k]);
            a = fa[a][k];
        }
    
    if (a != b)
    {
        //再让a和b一起往上跳直到跳到同一个点
        for (int k = 16; k >= 0; k -- )
            if (fa[a][k] != fa[b][k])  //如果跳后没有到同一个点，可以跳
            {
                distance.push_back(d1[a][k]);  //跳这一段的最大边和次大边都加入缓存区
                distance.push_back(d2[a][k]);
                distance.push_back(d1[b][k]);
                distance.push_back(d2[b][k]);
                a = fa[a][k], b = fa[b][k];  //跳
            }
        distance.push_back(d1[a][0]);  //lca是f[a][0],还要记得加上这两条边
        distance.push_back(d1[b][0]);
    }

    //求整个缓存区的最大边和次大边
    int dist1 = -INF, dist2 = -INF;
    for (int t : distance)
    {
        if (t > dist1) dist2 = dist1, dist1 = t;
        else if (t < dist1 && t > dist2) dist2 = t;
    }

    if (w > dist1) return w - dist1;  //如果非树边w>最大树边，直接用w替换最大树边
    if (w > dist2) return w - dist2;  //如果非树边w=最大树边，只能用w替代次大树边
    return INF;  //否则这条边不能用，结构正确的语句，没有实际含义【是不是其实没有这种情况，否则最小生成树构建错误？】
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }

    LL sum = kruskal();  //求最小生成树
    build();  //建立最小生成树
    bfs();  //预处理三个数组fa，d1，d2

    //枚举所有非树边，求次小生成树
    LL res = 1e18;
    for (int i = 0; i < m; i ++ )
        if (!edge[i].used)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            res = min(res, sum + lca(a, b, w));  //lca表示去掉a，b之间的最大边，同时加入w边
        }
    printf("%lld\n", res);

    return 0;
}