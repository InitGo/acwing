#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, M = 510;

int n, V1, V2;
int f[N][M];

int main()
{
    cin >> V1 >> V2 >> n;
    for (int i = 0; i < n; i ++ )
    {
        int v1, v2;
        cin >> v1 >> v2;
        for (int j = V1; j >= v1; j -- )
            for (int k = V2 - 1; k >= v2; k -- )
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
    }

    cout << f[V1][V2 - 1] << ' '; //费用2不能等于零
    int k = V2 - 1; 
    while (k > 0 && f[V1][k - 1] == f[V1][V2 - 1]) k -- ; //k-1后和最大值相等，则减1
    //可以走这条路，再走。先判断，再处理。 而不是处理了再判断
    cout << V2 - k << endl;

    return 0;
}