#include <iostream>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = f[i - 1][j];  //左半边子集合的答案：a[i]不取的的部分
            if (a[i] == b[j])  //如果a[i]==b[j],a[i]可以取
            {
                int maxv = 1; //右半边子集合的答案，a[i]取上
                for (int k = 1; k < j; k ++ ) //k的情况
                    if (b[k] < b[j])
                        maxv = max(maxv, f[i - 1][k] + 1);
                
                f[i][j] = max(f[i][j], maxv);
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[n][i]);
    
    cout << res << endl;
    
    return 0;
}