#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
char g[N][N];
bool st[N][N];
int xa, ya, xb, yb;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

bool dfs(int x, int y)
{
    if (g[x][y] == '#') return false;
    if (x == xb && y == yb) return true;

    st[x][y] = true;

    for (int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n) continue;
        if (st[a][b]) continue;
        //if (g[a][b] == '#') continue;

        if (dfs(a, b)) return true;
    }
    
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> g[i];
        cin >> xa >> ya >> xb >> yb;
        memset(st, 0, sizeof st);

        if (dfs(xa, ya)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}