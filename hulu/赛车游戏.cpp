#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int n;
int w[N];
int cnt;

void dfs(int u)
{
    if (w[u] == -1) return;
    if ((u << 1) > n && (u << 1 | 1) > n)
    {
        cnt ++ ;
        return;
    }
    if ((u << 1) <= n) dfs(u << 1);
    if ((u << 1 | 1) <= n) dfs(u << 1 | 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    dfs(1);
    cout << cnt << endl;
    return 0;
}

