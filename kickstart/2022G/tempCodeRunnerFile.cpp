#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 400010;

int n;
int a[N], s[N];
PII num[N];

int sum(int l, int r)
{
    return s[r] - s[l - 1];
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
        for (int i = 1; i <= n; i ++ ) num[i] = {a[i], i};

        sort(num + 1, num + n + 1);
        int start = 1;
        while (start <= n && num[start].first < 0) start ++ ;

        int ans = 0;
        for (int k = start; k <= n; k ++ )
        {
            int i = num[k].second;
            for (int j = i; j <= n; j ++ )
                if (sum(i, j) >= 0)
                    ans += sum(i, j);
                else break;
        }

        printf("Case #%d: %d\n", C, ans);
    }
}