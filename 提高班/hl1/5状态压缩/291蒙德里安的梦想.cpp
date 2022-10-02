//https://www.acwing.com/activity/content/problem/content/1010/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;
LL f[N][M]; //合法的方案数一般比较大， 用LL存
vector<int> state[M]; 
//state[j]是一个vector，存的是状态k，
//j与k满足：【第i-1列伸出来的状态/第i列的状态】为j，【第i-i列的状态/第i-2列伸出来的状态】为k， j的所有合法匹配为k
bool st[M]; //所有不连续含奇数个0的状态 st[i] = true

int main()
{
    while (cin >> n >> m, n || m) //n行， m列
    {
        int s = 1 << n; //s表示状态的上限 1 << n
        for (int i = 0; i < s; i ++ ) //枚举每种状态i
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j ++ ) //枚举状态i的每一位
            {
                if (i >> j & 1) //该位是1
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else cnt ++ ; //该位是0
            }
            if (cnt & 1) is_valid = false;
            st[i] = is_valid; //存下i状态是否合法
        }

        for (int j = 0; j < s; j ++ )
        {
            state[j].clear();
            for (int k = 0; k < s; k ++ )
                if ((j & k) == 0 && st[j | k])
                    state[j].push_back(k);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < s; j ++ )
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}