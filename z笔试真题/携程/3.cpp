#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL a[15];

int main()
{
    a[0] = 233;
    for (int i = 1; i <= 12; i ++ ) a[i] = a[i - 1] * 10;

    int n;
    cin >> n;
    while (n -- )
    {
        LL x;
        cin >> x;
        if (x % 233) cout << -1 << endl;
        else
        {
            int cnt = 0;
            for (int i = 12; i >= 0 && x; i -- )
            {
                if (x >= a[i])
                {
                    int carry = x / a[i];
                    x -= carry * a[i];
                    cnt += carry;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}