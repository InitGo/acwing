#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 50;

int n, m, k;
int w[N];
vector<int> path;
int ans = 0;

int find(int x)
{
    int l = 0, r = path.size() - 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (path[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return path[l];
}

void dfs1(int u, int sum)
{
    if (u >= k)
    {
        path.push_back(sum);
        return;
    }
    
    dfs1(u + 1, sum);
    if ((LL)sum + w[u] <= m) dfs1(u + 1, sum + w[u]);
}

void dfs2(int u, int sum)
{
    if (u >= n)
    {
        int t = m - sum;
        ans = max(ans, find(t) + sum);
        return;
    }
    
    dfs2(u + 1, sum);
    if ((LL)sum + w[u] <= m) dfs2(u + 1, sum + w[u]);

}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    sort(w, w + n);
    reverse(w, w + n);
    
    k = n / 2;
    if (n > 40) k = n / 2 + 2;
    
    dfs1(0, 0);
    
    sort(path.begin(), path.end());
    path.erase(unique(path.begin(), path.end()), path.end());
    
    dfs2(k, 0);
    
    cout << ans << endl;
    return 0;
}