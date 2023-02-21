#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
int cat[N];
int sum[N];
int ans = N;

//当前枚举到第u只猫，当前车数量为k
void dfs(int u, int k)
{
    if (k >= ans) return;
    if (u == n)
    {
        ans = k;
        return;
    }
    
    for (int i = 0; i < k; i ++ )
        if (cat[u] <= m - sum[i]) //可行性剪枝
        {
            sum[i] += cat[u];
            dfs(u + 1, k);
            sum[i] -= cat[u];
        }
    
    sum[k] += cat[u];
    dfs(u + 1, k + 1);
    sum[k] -= cat[u];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> cat[i];
    
    sort(cat, cat + n);
    reverse(cat, cat + n);
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}