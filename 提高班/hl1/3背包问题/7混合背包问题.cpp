#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
    {
        int v, w, s;
        cin >> v >> w >> s;
        if (!s) //s == 0 完全背包问题
        {
            for (int j = v; j <= m; j ++ )
                f[j] = max(f[j], f[j - v] + w);
        }
        else
        {
            if (s == -1) s = 1; //01背包是特殊的数量为1的多重背包，s = 1，继续做多重背包
            for (int k = 1; k <= s; k *= 2) // 枚举每件物品 体积=k*v， 价值=k*w
            {
                for (int j = m; j >= k * v; j -- ) //枚举体积
                    f[j] = max(f[j], f[j - k * v] + k * w); 
                s -= k; //每件物品做完 s -= k
            }
            if (s) //剩下的那一部分，是一件物品
            {
                for (int j = m; j >= s * v; j -- ) //体积=s*v， 价值=s*w
                    f[j] = max(f[j], f[j - s * v] + s * w);
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}