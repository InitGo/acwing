#include <iostream>

using namespace std;

const int N = 110;

int h[N];
int n;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int p = 1; p <= T; p ++ )
    {
        cin >> n;

        for (int i = 1; i <= n; i ++ ) cin >> h[i];
        
        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (i == 1 || i == n) continue;
            if (h[i] > h[i - 1] && h[i] > h[i + 1]) res ++ ;
        }

        printf("Case #%d: %d\n", p, res);
    }

    return 0;
}