#include <bits/stdc++.h>

using namespace std;

const int M = 1010, N = 33;

int n, m, p;

int max_score[N];
int my_score[N];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        memset(max_score, 0, sizeof max_score);
        cin >> m >> n >> p;
        for (int i = 1; i <= m; i ++ )
        {
            if (i == p)
                for (int j = 1; j <= n; j ++ ) cin >> my_score[j];
            else
            {
                int x;
                for (int j = 1; j <= n; j ++ )
                {
                    cin >> x;
                    max_score[j] = max(max_score[j], x);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            if (my_score[i] < max_score[i])
                ans += max_score[i] - my_score[i];

        printf("Case #%d: %d\n", C, ans);
    }
}