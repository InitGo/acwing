#include <bits/stdc++.h>

using namespace std;

const int N = 40010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int f[N][16], depth[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int root)
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;  //0是哨兵，规定depth[0] = 0是非法值0， root的depth[root] = 1
    queue<int> q;
    
    q.push(root);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1) //j没有被更新过
            {
                //先把j入队列
                q.push(j);  

                //处理depth[j]
                depth[j] = depth[t] + 1;  
                
                //处理j的f数组
                f[j][0] = t;  
                for (int k = 1; k <= 15; k ++ )
                    f[j][k] = f[f[j][k - 1]][k - 1];
            }
        }
    }
    
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);  //让a在更深，然后操作a往上跳
    
    //从小到大枚举k，二进制拼凑depth，先让a和b跳到同一层
    for (int k = 15; k >= 0; k -- )
        if (depth[f[a][k]] >= depth[b]) //如果a上跳2^k步到f[a][k]后，depth[f[a][k]] >= depth[b]，那么就可以跳
            a = f[a][k];                //添加哨兵的优化1：不需要判断是否跳出界，因为如果出界，depth=0，则一定不满足if内的要求

    //判断一下是否找到lca
    if (a == b) return a;
    
    //如果没找到，a和b同时往上跳
    for (int k = 15; k >= 0; k -- ) 
        if (f[a][k] != f[b][k])  //如果跳完了二者不等，那就可以跳  
        {                        //添加哨兵的优化2：少了很多边界判断，如果二者跳出界，那么二者都跳到哨兵，必然相等
            a = f[a][k];
            b = f[b][k];
        }
    
    //此时f[a][0] == f[b][0] == lca
    return f[a][0];
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    int root = 0;
    
    for (int i = 0; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        if (b == -1) root = a;
        else add(a, b), add(b, a);
    }
    
    bfs(root);  //用bfs预处理depth和f数组
    
    cin >> m;  //处理询问
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        if (p == a) cout << 1 << endl;
        else if (p == b) cout << 2 << endl;
        else cout << 0 << endl;
    }
    return 0;
}