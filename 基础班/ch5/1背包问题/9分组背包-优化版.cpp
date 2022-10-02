//https://www.acwing.com/activity/content/problem/content/1001/
#include <iostream>

using namespace std;

const int N = 110;

int n, m;
int f[N];
int v[N][N], w[N][N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j ++ )
            cin >> v[i][j] >> w[i][j];
    }
    
    for (int i = 1; i <= n; i ++ )  //枚举物品
        for (int j = m; j >= 0; j -- )  //枚举体积
            for (int k = 1; k <= s[i]; k ++ ) //枚举每个选择
                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;
    return 0;
}