#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++ )
    {
        cin >> n >> m;
        int sum = 0;
        while (n -- )
        {
            int x;
            cin >> x;
            sum += x;
        }
        printf("Case #%d: %d\n", i, sum % m);
    }
    return 0;
}