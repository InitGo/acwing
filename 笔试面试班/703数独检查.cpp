#include <bits/stdc++.h>

using namespace std;

const int N = 38;

int n, m;
int g[N][N];
bool st[40];

bool check_row()
{
    for (int i = 0; i < m; i++) //遍历行
    {
        memset(st, 0, sizeof st);
        for (int j = 0; j < m; j++)
        {
            int x = g[i][j];
            if (x < 1 || x > m || st[x])
                return false;
            st[x] = true;
        }
    }
    return true;
}

bool check_col()
{
    for (int i = 0; i < m; i++) //遍历行
    {
        memset(st, 0, sizeof st);
        for (int j = 0; j < m; j++)
        {
            int x = g[j][i];
            if (x < 1 || x > m || st[x])
                return false;
            st[x] = true;
        }
    }
    return true;
}

//每个blokc左上角的位置可以唯一确定一个block
//有scale的定位方法： i += n;
bool check_block()
{
    for (int i = 0; i < m; i += n)
        for (int j = 0; j < m; j += n)
        {
            memset(st, 0, sizeof st);
            for (int di = 0; di < n; di++)
                for (int dj = 0; dj < n; dj++)
                {
                    int x = g[i + di][j + dj];
                    if (x < 1 || x > m || st[x])
                        return false;
                    st[x] = true;
                }
        }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        cin >> n;
        m = n * n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        if (check_row() && check_col() && check_block())
            printf("Case #%d: Yes\n", C);
        else
            printf("Case #%d: No\n", C);
    }
    return 0;
}