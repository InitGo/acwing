#include <iostream>

using namespace std;

const int N = 110, INF = 1e4;

int f[N][N], a[N][N];
int n;

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            //！！！一定要学会这中处理边界情况的写法
            if (i == 1 && j == 1) f[i][j] = a[i][j]; //特判如果是第一个位置
            else
            {
                f[i][j] = INF; //求min，初始设置为INF
                //特判 只有能走的路才比较
                if (i > 1) f[i][j] = min(f[i][j], f[i-1][j] + a[i][j]); 
                if (j > 1) f[i][j] = min(f[i][j], f[i][j-1] + a[i][j]);
            }
        }
    }
    
    cout << f[n][n] << endl;
    
    return 0;
}