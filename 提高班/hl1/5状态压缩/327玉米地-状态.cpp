#include <bits/stdc++.h>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int n, m;
int w[N];
vector<int> state;
vector<int> head[M];
int f[N][M];

bool check(int state)
{
    return !(state & state >> 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            int t;
            cin >> t;
            w[i] += !t << j; //把坏地标记为1
        }
        
    for (int i = 0; i < 1 << m; i ++ )
        if (check(i))
            state.push_back(i);

    for (int a : state)
        for(int b : state)
            if ((a & b) == 0)
                head[a].push_back(b);
 
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i ++ )
        for (auto a : state)
            if (!(a & w[i]))
                for (int b : head[a])
                    f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
                    // if(!(b & w[i -1])) 
                    //     f[i][a] = (f[i][a] + f[i - 1][b]) % mod;


    cout << f[n + 1][0] << endl;
    return 0;
}