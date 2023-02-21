#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 25, INF = 1e9;

int n, m;
int minv[N], mins[N];
int R[N], H[N];
int ans = INF;

void dfs(int u, int v, int s)
{
    if (v + minv[u] > n) return;
    if (s + mins[u] >= ans) return;
    if (s + 2 * (n - v) / R[u + 1] >= ans) return;

    if (!u)
    {
        if (v == n) ans = s;
        return;
    }

    for (int r = min(R[u + 1] - 1, (int)sqrt(n - v)); r >= u; r -- )
        for (int h = min(H[u + 1] - 1, (n - v) / r / r); h >= u; h -- )
        {
            int t = 0;
            if (u == m) t = r * r;
            R[u] = r, H[u] = h;
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t);
        }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i ++ )
    {
        minv[i] = minv[i - 1] + i * i * i;
        mins[i] = mins[i - 1] + 2 * i * i;
    }

    R[m + 1] = H[m + 1] = INF;

    dfs(m, 0, 0);

    if (ans == INF) ans = 0;
    cout << ans << endl;

    return 0;
}