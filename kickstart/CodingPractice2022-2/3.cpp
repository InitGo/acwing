#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, q;
char ele[N];
int st[28]; //0~25

bool check(int l, int r)
{
    
    memset(st, 0, sizeof st);
    for (int i = l; i <= r; i ++ )
    {
        int c = ele[i] - 'A';
        st[c] ++ ;
    }

    int odd = 0;
    for (int i = 0; i < 26; i ++ )
    {
        if (st[i] % 2 != 0) odd ++ ;
    }

    if (odd > 1) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++ )
    {
        cin >> n >> q;
        cin >> ele + 1;

        int cnt = 0;
        while (q -- )
        {
            int l, r;
            cin >> l >> r;

            if (check(l, r)) cnt ++ ;
        }

        printf("Case #%d: %d\n", i, cnt);
    }
}