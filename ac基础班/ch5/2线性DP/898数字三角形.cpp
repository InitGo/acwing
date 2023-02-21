//https://www.acwing.com/activity/content/problem/content/1002/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int n;
int a[N][N];
int f[N][N];

int main()
{
    scanf("%d", &n);
    //读入a[N][N]
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            scanf("%d", &a[i][j]);

    //初始化f[N][N] ！！！这里不是初始化原始矩阵，而是初始化f，没有路的地方f是负无穷
    for (int i = 0; i <= n; i ++ ) 
        for (int j = 0; j <= i + 1; j ++ ) 
        //每一行多初始化一个位置，最外列的右上角也会计算，初始化成-INF
            f[i][j] = -INF;

    f[1][1] = a[1][1]; //初始化第一个位置
    for (int i = 2; i <= n; i ++ ) //从第2行开始
        for (int j = 1; j <= i; j ++ )
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    int res = -INF; //这里不是初始化0而是负无穷，因为矩阵的值存在负数 ！！！要注意数据范围
    //遍历最后一行，找到最大值
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);

    printf("%d\n", res);
    return 0;
}