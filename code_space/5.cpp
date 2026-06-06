#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 2 * N;

int n;
int val[N];
int h[N], e[M], ne[M], idx;
int ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//返回以u为根的子树的节点和，不包括u；
int dfs(int u)
{
    int sum = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        int t = dfs(j);  //某一个子树子树的和
        sum += t + val[j];
    }
    if (sum == 0) ans ++ ;
    return sum;
}

int main()
{
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i ++ )
        if (s[i - 1] == 'R') val[i] = -1;
        else val[i] = 1;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; i ++ )
    {
        int p;
        cin >> p;
        add(p, i + 1);
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}