#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 2 * N, K = 16;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N], fa[N][K + 1], depth[N];
int ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs()
{
    depth[1] = 1;
    queue<int> q;
    q.push(1);
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!depth[j])
            {
                depth[j] = depth[t] + 1;
                q.push(j);
                
                fa[j][0] = t;
                for (int k = 1; k <= K; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = K; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
            
    if (a == b) return a;
    
    for (int k = K; k >= 0; k -- )
    {
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}

int dfs(int u, int parent)
{
    int res = d[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == parent) continue;
        
        int s = dfs(j, u);
        if (s == 0) ans += m;
        else if (s == 1) ans ++ ;
        res += s;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bfs();  //预处理两个数组

    for (int i = 0; i < m; i ++ )  //依次处理每条非树边
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        d[a] ++, d[b] ++, d[p] -= 2;
    }
    
    dfs(1, -1);  //dfs统计每个子树节点值之和
    
    cout << ans << endl;  //输出方案数

    return 0;
}

