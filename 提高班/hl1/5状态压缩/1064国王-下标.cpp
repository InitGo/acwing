#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;
int cnt[M];
vector<int> head[M];
LL f[N][K][M];

//检查状态state是否合法：有两个连续的1为不合法false
// i & i >> 1 也可以直接检查  i & i >> 1为true则不合法
bool check(int state)
{
    for (int i = 0; i < n; i ++ )
        if ((state >> i & 1) && (state >> i + 1 & 1)) //第i位是1 && 第i+1位是1
            return false;
    return true;
}

//计算状态中1的个数
int count(int state)
{
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += state >> i & 1;
    return res;
}

int main()
{
    cin >> n >> m; //n*n的棋盘， 有m个棋子可以摆

    for (int i = 0; i < 1 << n; i ++ )
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }

    for (int i = 0; i < state.size(); i ++ )
        for (int j = 0; j < state.size(); j ++ )
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j); 
                //head[i][j]表示state数组中的第i个状态可以转移到第j个状态
                //head[i][j] : state[i] --> state[j]
        }

    f[0][0][0] = 1; //做完了前0行（还没开始做），已经放了0个旗子（还没开始放），第0行状态是0 ---> 为一种方案
    for (int i = 1; i <= n + 1; i ++ ) //枚举行 到n+1
        for (int j = 0; j <= m; j ++ ) //枚举棋子个数
            for (int a = 0; a < state.size(); a ++ ) //枚举state下标 a
                for (int b : head[a]) //state[a]可以转移到的所有state[b]
                {
                    int c = cnt[state[a]];
                    if (j >= c)
                        f[i][j][a] += f[i - 1][j - c][b];
                }

    cout << f[n + 1][m][0] << endl;
    //已经做完n+1行，放好了m个棋子，第n+1行摆放状态是0（什么都没有摆）
    //等价于 摆好n行

    return 0;
}