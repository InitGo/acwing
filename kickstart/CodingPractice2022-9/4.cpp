#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        cin >> n;
        while (n -- )
        {
            int l, r;
            cin >> l >> r;
            insert(l, r, 1);
        }

        for (int i = 1; i <= N; i ++ ) a[i] = a[i - 1] + b[i];

        cin >> m;
        printf("Case #%d: ", C);
        while (m -- )
        {
            int x;
            cin >> x;
            cout << a[x] << ' ';
        }
        cout << endl;
    }
    return 0;
}