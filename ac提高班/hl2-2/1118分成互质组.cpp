#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int n;
int num[N];
vector<int> g[N];
int ans = N;

int gcd(int a, int b) //返回a与b的最大公约数
{
    return b ? gcd(b, a % b) : a;
}

bool check(int x, int c) //数字x与数组g[c]中的数字是否全部互质
{
    for (int i = 0; i < g[c].size(); i ++ )
        if (gcd(x, g[c][i]) > 1)
            return false;
    return true;
}

//当前正在处理第u个数，当前有k个数组
void dfs(int u, int k)
{
    if (k >= ans) return;
    if (u == n)
    {
        ans = k;
        return;
    }
    
    //加入到已有数组中
    for (int i = 0; i < k; i ++ )
    {
        if (check(num[u], i))
        {
            g[i].push_back(num[u]);
            dfs(u + 1, k);
            g[i].pop_back();
        }
    }
    
    //开新的数组
    g[k].push_back(num[u]);
    dfs(u + 1, k + 1);
    g[k].pop_back();
    
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> num[i];
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}

