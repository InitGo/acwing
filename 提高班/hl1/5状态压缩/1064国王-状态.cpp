#include <bits/stdc++.h>

using namespace std;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;
int cnt[M];
long long f[N][K][M];
vector<int> head[M];

bool check(int state)
{
    for (int i = 0; i < n; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1)) //第i位是1 && 第i+1位是1
            return false;
    return true;
}

int count(int s)
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += s >> i & 1;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < 1 << n; i ++ )
    {
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    
    for (int a : state)
        for (int b : state)
            if ((a & b) == 0 && check(a | b))
                head[a].push_back(b);
        
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i ++ )
        for (int j = 0; j <= m; j ++)
            for (int a : state)
                for (int b : head[a])
                    if (j >= cnt[a])  
                        f[i][j][a] += f[i - 1][j - cnt[a]][b];
    
    cout << f[n + 1][m][0] << endl;
    return 0;
}