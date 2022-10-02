#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m, h, w;
string g[N], target[N];

bool check(int x, int y)
{
    if (x + h - 1 >= n && y + w - 1 >= m) return false;

    for (int i = 0; i < h; i ++ )
        for (int j = 0; j < w; j ++ )
            if (target[i][j] != g[x + i][y + j])
                return false;
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> g[i];
    cin >> h >> w;
    for (int i = 0; i < h; i ++ ) cin >> target[i];

    int cnt = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (check(i, j))
                cnt ++ ;
    cout << cnt << endl;
    return 0;
}

