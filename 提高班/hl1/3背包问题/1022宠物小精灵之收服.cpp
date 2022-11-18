#include <iostream>

using namespace std;

const int N = 110, M1 = 1010, M2 = 510;

int m1, m2, n;
int f[M1][M2];

int main()
{
    cin >> m1 >> m2 >> n;
    
    for (int i = 1; i <= n; i ++ )
    {
        int v1, v2;
        cin >> v1 >> v2;
        for (int j = m1; j >= v1; j -- )
            for (int k = m2 - 1; k >= v2; k -- )
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
    }
    
    cout << f[m1][m2 - 1] << " ";
    
    int price = m2 - 1;
    while (price > 0 && f[m1][price - 1] == f[m1][m2 - 1]) price -- ;
    cout << m2 - price << endl;
    return 0;
}