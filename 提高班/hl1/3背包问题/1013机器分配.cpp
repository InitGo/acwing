#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11, M = 16;

int n, m;
int w[N][M];
int f[N][M];
int way[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> w[i][j];

    //要输出方案，不能降维
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= m; j ++ )
            for (int k = 0; k <= j; k ++ )
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);

    cout << f[n][m] << endl;

    //是在求具体方案，
    int j = m; //体积初始化=m
    for (int i = n; i; i -- ) //倒序枚举物品
        for (int k = 0; k <= j; k ++ ) //枚举决策 这里选0和选k可以合并【一般情况下不能合并】
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) //转移
            {
                way[i] = k; //记录第i组物品选了第k个，从前往后输出，这里用数组记录
                j -= k; //减去第k个的体积
                break; //第i组的方案已经查到了，break
            }

    for (int i = 1; i <= n; i ++ ) cout << i << ' ' << way[i] << endl; //输出

    return 0;
}