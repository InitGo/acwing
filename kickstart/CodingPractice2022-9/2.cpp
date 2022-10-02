#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        
        if (n == 1)
        {
            printf("Case #%d: %d\n", C, 1);
            continue;
        }

        int maxn = 0, res = 0;
        for (int i = 0; i < n; i ++ )
        {
            if (i == 0)
            {
                if ( i + 1 < n && a[i] > a[i + 1]) res ++ ;
                maxn = max(maxn, a[i]);
            }
            if (i == n - 1 && a[i] > maxn) res ++ ;
            if (i >= 1 && i < n - 1)
            {
                if (a[i] > maxn && a[i] > a[i + 1])
                {
                    res ++ ;
                    maxn = a[i];
                }
            }
        }
        printf("Case #%d: %d\n", C, res);
    }
    return 0;
}