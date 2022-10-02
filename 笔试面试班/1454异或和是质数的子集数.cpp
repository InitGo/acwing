#include <iostream>

using namespace std;

const int N = 5010, M = 8192, mod = 1e9 + 7;

int n;
int a[N];
int f[2][M];

bool is_prime(int x) 
{
    if (x < 2) return false; //可以注释，因为主函数里j是从2开始枚举
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < M; j ++ )
        {
            f[i & 1][j] = f[i- 1 & 1][j];
            if ((j ^ a[i]) < M) f[i & 1][j] = (f[i & 1][j] + f[i- 1 & 1][j ^ a[i]]) % mod;
        }
    //因为计算第i层只用到了第i-1层的值
        
    //最后求解答案的时候也只用到了第n层，即最后一层保存的结果
    //所以可以使用滚动数组优化
    int sum = 0;
    for (int j = 2; j < M; j ++ )
        if (is_prime(j)) sum = (sum + f[n & 1][j]) % mod;
    cout << sum << endl;
    
    return 0;
}

//滚动数组：所有，所有的f第一维都要&1
