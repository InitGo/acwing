#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;
bool st[M];
vector<int> state[M];
LL f[N][M];

//检查状态i是否是 没有奇数个相连的0
bool check(int i)
{
    bool is_valid = true;
    int cnt = 0;
    for (int j = 0; j < n; j ++ )
    {
        if (i >> j & 1)
        {
            if (cnt & 1) 
            {
                is_valid = false;
                break;
            }
        }
        else cnt ++ ;
    }
    
    if (cnt & 1) is_valid = false;
    return is_valid;
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        memset(st, 0, sizeof st);
        for (int i = 0; i < 1 << n; i ++ )
            st[i] = check(i);
        
        for (int i = 0; i < 1 << n; i ++ )
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j ++ )
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }
        
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (int k = 0; k < state[j].size(); k ++ )
                    f[i][j] += f[i - 1][state[j][k]];
        cout << f[m][0] << endl;
    }
    return 0;
}

