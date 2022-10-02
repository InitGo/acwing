#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = 2 * N;

int n;
int h[N], e[M], w[M], ne[M], idx;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

//返回以u为根节点的子树的最长深度
int dfs(int u, int parent)
{
    int d1 = 0, d2 = 0; //存当前子树的最长和次长深度 初始化成0，避免负数
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == parent) continue; //如果是 母节点，continue
        int d = dfs(j, u) + w[i]; //从u经过j子节点的分支的最长深度d

        if (d > d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;

        ans = max(ans, d1 + d2);
    }
    return d1;
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

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}