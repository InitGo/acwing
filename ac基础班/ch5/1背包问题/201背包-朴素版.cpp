//https://www.acwing.com/activity/content/problem/content/997/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    
    //f[0][0~m] 只从前0个物品选，总体积不超过0~m，所有选法的最大值是0
    //f是全局变量，所以不用初始化

    //f[i][j]表示所有从1~i号物品中选，且总体积不超过j的所有选法的价值最大值
    for (int i = 1; i <= n; i++) //从1开始枚举物品
    {
        for (int j = 0; j <= m; j++)  //枚举体积
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << endl;

    //f[i][j]表示所有从n~i号物品中选，且总体积不超过j的所有选法的价值最大值
    for (int i = n; i >= 1; i -- ) //从n开始枚举物品
    {
        for (int j = 0; j <= m; j ++ )
        {
            f[i][j] = f[i + 1][j]; //第i件不选，则从n~i+1中选
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    }
    cout << f[1][m] << endl;
    //这种写法，最后一步决策是否选第1件物品，加上题目中有用最小字典序输出方案的要求
    //所以就满足了从第一件物品开始回退倒推决策，得到选择的具体方案

    //是否可以先把物品逆序排序，再用正常的选法？
    return 0;
}