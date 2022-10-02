#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k, op;
int a[N], s[N];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n >> k >> op;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
        
        bool is_continue = true;
        int lower = N, greater = 0;
        for (int l = 1; l + k - 1 <= n; l ++ )
        {
            int r = l + k - 1;
            int lower = N, greater = 0;
            int sum = s[r] - s[l - 1];
            lower = min(lower, sum), greater = max(greater, sum);
            if (greater - lower > op)
            {
                cout << -1 << endl;
                is_continue = false;
                break;
            }
        }

        if (is_continue)
        {

        }
    }

}