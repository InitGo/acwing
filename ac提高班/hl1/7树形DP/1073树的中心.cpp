#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, M = N * 2, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N], p1[N], p2[N], up[N]; //p2[N]没必要记录,这里加深程序理解
bool is_leaf[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

//向下走
int dfs_d(int u, int mother)
{
    d1[u] = d2[u] = -INF;  //初始化为非法值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == mother) continue;
        int d = dfs_d(j, u) + w[i];
        if (d >= d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p2[u] = p1[u], p1[u] = j;
        }
        else if (d > d2[u]) d2[u] = d, p2[u] = j;
    }

    if (d1[u] == -INF) //如果这个点的最大长度没有被更新过,则标记为叶节点,最大长度为0
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }

    return d1[u];
}

//向上走,求up的值, 用mother节点的信息更新children节点
void dfs_u(int u, int mother)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == mother) continue;

        //用u去更新j的up的信息
        if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        //如果以u为根的子树的取得最长深度的路径经过j,则 up[j] = max(u向上走最长, u向下走次长) + g[u][j]
        else up[j] = max(up[u], d1[u]) + w[i];
        //否则, up[j] = max(u向上走最长, u向下走最长) + g[u][j]

        dfs_u(j, u);
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs_d(1, -1);
    dfs_u(1, -1);

    int res = d1[1];
    for (int i = 2; i <= n; i ++ )
        if (is_leaf[i]) res = min(res, up[i]);
        else res = min(res, max(d1[i], up[i]));

    printf("%d\n", res);

    return 0;
}