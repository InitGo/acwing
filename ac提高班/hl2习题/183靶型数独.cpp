#include <bits/stdc++.h>

using namespace std;

const int N = 9, M = 1 << N;

int row[N], col[N], cell[3][3];
int g[N][N];
int ans = -1;
int ones[M], mp[M];

int lowbit(int x)
{
    return x & -x;
}

void draw(int x, int y, int t, bool is_set)  //t 0~8
{
    if (is_set) g[x][y] = t + 1;
    else g[x][y] = 0;
    
    int v = 1 << t;
    if (!is_set) v = -v;
    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

int get(int x, int y)
{
    return row[x] & col[y] & cell[x / 3][y / 3];
}

int get_score(int x, int y, int t)
{
    return (min(min(x, 8 - x), min(y, 8 - y)) + 6) * t;
}

void dfs(int cnt, int score)
{
    if (cnt == 0)
    {
        ans = max(ans, score);
        return;
    }
    
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
        {
            if (g[i][j]) continue;
            int state = get(i, j);
            if (minv > ones[state])
            {
                minv = ones[state];
                x = i, y = j;
            }
        }
    
    for (int i = get(x, y); i; i -= lowbit(i))
    {
        int u = mp[lowbit(i)];
        draw(x, y, u, true);
        dfs(cnt - 1, score + get_score(x, y, u + 1));
        draw(x, y, u, false);
    }
}

void init()
{
    for (int i = 0; i < N; i ++ )
    {
        row[i] = M - 1;
        col[i] = M - 1;
    }
    
    for (int i = 0; i < 3; i ++ )
        for (int j = 0; j < 3; j ++ )
            cell[i][j] = M - 1;
    
    for (int i = 0; i < M; i ++ )
        for (int j = 0; j < N; j ++ )
            ones[i] += i >> j & 1;
    
    for (int i = 0; i < N; i ++ )
        mp[1 << i] = i;
}

int main()
{
    init();
    
    int cnt = 0, score = 0;
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
        {
            int x;
            cin >> x;
            if (x == 0) cnt ++ ;
            else 
            {
                draw(i, j, x - 1, true);
                score += get_score(i, j, x);
            }
        }
        
    dfs(cnt, score);
    
    cout << ans << endl;
    
    return 0;
}