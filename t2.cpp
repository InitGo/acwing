#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int h[N], e[N], ne[N], idx;
int din[N], son[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}


//返回p的子树的节点个数，不包括p
int dfs(int p)
{
    int sum = 0;
    for (int i = h[p]; ~i; i = ne[i])
    {
        int j = e[i];
        sum += dfs(j);
        sum += 1;
    }
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ ) 
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        din[a] ++ ;
    }

    int root = -1;
    for (int i = 1; i <= n; i ++ )
        if (!din[i])
        {
            root = i;
            break;
        }

    dfs(root);


}