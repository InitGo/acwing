#include <iostream>

using namespace std;

const int N =  1010;

int f[N];
int v[4] = {10, 20, 50, 100};

int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 0; i < 4; i ++ )
    {
        for (int j = v[i]; j <= n; j ++ )
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[n] << endl;
    return 0;
}




#include <iostream>

using namespace std;

const int N = 1010;

int m;
int f[5][N];

int main()
{
    cin >> m;
    int price[] = {0, 10, 20, 50, 100};
    //for (int i = 0; i <= 4; i ++ ) f[i][0] = 1; 为什么这里用for初始化就不对？
    f[0][0] = 1;
    for (int i = 1; i <= 4; i ++ )
        for (int j = 0; j <= m; j ++ )
            for (int k = 0; k * price[i] <= j; k ++ )
                f[i][j] += f[i - 1][j - k * price[i]];
    cout << f[4][m] << endl;
    return 0;
}