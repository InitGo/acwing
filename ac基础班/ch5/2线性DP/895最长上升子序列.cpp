//https://www.acwing.com/activity/content/problem/content/1003/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

    //枚举以每个点为结尾点
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1; // 只有a[i]一个数 (j=0) 
        for (int j = 1; j < i; j ++ ) //(j = 1 ~ i-1) 上升子序列的倒数第二个位置的数的下标是j
            if (a[j] < a[i]) //满足条件才能算
                f[i] = max(f[i], f[j] + 1);
    }

    int res = 0;
    //枚举 每个点结尾的上升子序列的个数最大值，找到最大值
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i]);

    printf("%d\n", res);

    return 0;
}