//https://www.acwing.com/activity/content/problem/content/1008/

//完全背包思想的解法

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

int main()
{
    cin >> n;

    f[0] = 1; //容量为0时，前 i 个物品全不选也是一种方案
    for (int i = 1; i <= n; i ++ ) //从前i个物品选
        for (int j = i; j <= n; j ++ ) //体积恰好是j, 因为有j-i所以j从i开始,避免if判断
            f[j] = (f[j] + f[j - i]) % mod;

    cout << f[n] << endl;

    return 0;
}