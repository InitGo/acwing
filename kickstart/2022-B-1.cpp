#include <iostream>
#include <math.h>

using namespace std;

typedef long long LL;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int e = 1; e <= t; e ++ )
    {
        int r, a, b;
        cin >> r >> a >> b;

        bool left = true;
        LL radius = r;
        LL cnt = 0;
        
        cnt += radius * radius;
        
        while (radius > 0)
        {
            if (left) radius *= a;
            else radius /= b;

            left = !left;
            if (radius > 0) cnt += radius * radius;
        };

        double res = cnt * acos(-1);
        printf("Case #%d: %.6lf\n", e, res);
    }
    return 0;
}