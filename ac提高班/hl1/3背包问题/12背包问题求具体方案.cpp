#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i]; //读入信息

    for (int i = n; i >= 1; i -- ) //倒序处理每件物品【需要字典序输出】 从第n件物品做到第1件
        for (int j = 0; j <= m; j ++ ) //是二维，循环顺序任意
        {
            f[i][j] = f[i + 1][j]; //先让f[i][j] = 不选i的情况
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]); //选i的情况
        }

    int j = m; //j首先等于m，初始：什么都还没选，容量是m
    for (int i = 1; i <= n; i ++ )  //!!!枚举物品，与决策顺序相反
    //如果第i个物品 可选/必选 ，则选上   前面倒序枚举每件物品，所以这里可以从1开始往回推导
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
        {
            cout << i << ' '; //选上i，输出
            j -= v[i]; //选了第i个物品，剩余容量就要减小
        }

    return 0;
}