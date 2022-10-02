#include <iostream>

using namespace std;

const int N = 410;

int f[N][N];
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int t;
    cin >> t;

    for (int e = 1; e <= t; e ++ )
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i ++ )
        {
            int c;
            cin >> c;
            insert(i, i, c);
        }

        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= n; j ++ )
            {
                if (i <= j)
                {
                    f[i][j] = j - i;
                    
                    
                    for (int k = 1; k <= n; k ++ ) a[k] = a[k - 1] + b[k];
                    
                    int l = i, r = j;
                    for (; l < r;l ++ , r -- )
                    {
                        if (a[l] != a[r]) break;
                    }

                    if (l != i)
                    {
                        f[i][j] = min(f[i][j], f[l][r] + 1);
                    }
                    else
                    {
                        f[i][j] = min(f[i][j], f[i+1][j] + 1);
                        f[i][j] = min(f[i][j], f[i][j-1] + 1);
                    }
                }
            }
        }


    }
}