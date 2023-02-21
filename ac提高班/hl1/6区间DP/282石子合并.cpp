//https://www.acwing.com/activity/content/problem/content/1007/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;

int n;
int s[N]; //前缀和
int f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &s[i]);

    for (int i = 1; i <= n; i ++ ) s[i] += s[i - 1];

    //如果区间长度是1，合并代价是0【用全局变量初始化了，不需要再做】，所以区间长度从2开始
    for (int len = 2; len <= n; len ++ ) //按照区间长度从小到大 枚举状态
        for (int i = 1; i + len - 1 <= n; i ++ ) //i枚举区间的起点 ，其中起点从1开始，满足 i-len+1<=n 
        {
            //知道起点坐标i 区间长度len
            int l = i, r = i + len - 1; //可以算出左右端点

            // 已经知道左右端点，可以枚举k，进行递推了
            f[l][r] = 1e8; //因为是求min，在算之前初始化为inf
            for (int k = l; k < r; k ++ ) //枚举分界位置，假设分界位置位于[k,k+1]之间 (k = l ~ r - 1)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    
    //写法2
    // memset(f, 0x3f, sizeof f); //预先初始化
    // for (int len = 1; len <= n; len ++ )
    //     for (int i = 1; i + len - 1 <= n; i ++ )
    //     {
    //         int l = i, r = i + len - 1;
    //         if (len == 1) f[l][r] = 0; //当长度为1，则开销为0
    //         for (int k = l; k < r; k ++ )
    //             f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + a[r] - a[l - 1]);
    //     }
    
    //写法3
    // for (int len = 2; len <= n; len ++ )
    // {
    //     for (int i = 1; i + len - 1 <= n; i ++ )
    //     {
    //         int j = i + len - 1;
    //         f[i][j] = 1e8;
    //         for (int k = i ; k < j; k ++ )
    //         {
    //             f[i][j] = min (f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
    //         }
    //     }
    // }

    printf("%d\n", f[1][n]); //最终答案是 第1堆到第n堆合并的 代价
    return 0;
}