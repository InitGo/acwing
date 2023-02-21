#include <iostream>

using namespace std;

const int N = 1010;

int n;
int q[N];
int f[N];
int g[N]; //存储当前现有的所有子序列

int main()
{
    while (cin >> q[n]) n ++ ;

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        f[i] = 1;
        for (int j = 0; j < i; j ++ )
        {
            if (q[j] >= q[i])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;

    int cnt = 0; //表示当前子序列的个数
    for (int i = 0; i < n; i ++ ) //从前往后看序列
    {
        int k = 0; //k表示从前往后找的序列 下标
        while (k < cnt && g[k] < q[i]) k ++ ; //没有遍历完 && 当前序列的结尾小于当前数 --> 循环结束后就找到了结尾大于等于当前数的最小的子序列
        g[k] = q[i]; //把当前数接到k序列后面 【g[k]的结尾变成当前数】
        if (k >= cnt) cnt ++ ; //所有序列结尾的数都小于当前数，开新的子序列
    }

    cout << cnt << endl;

    return 0;  
}