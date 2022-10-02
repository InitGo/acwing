#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

ll n, k;
int have[N];
int need[N];
int nst[N];
bool st[N];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> need[i];
    for (int i = 0; i < n; i ++ ) nst[i] = (i + 1) % n;

    int last_id = -1;
    for (ll i = 1; i <= k; i ++ )
    {
        int start;
        if (last_id >= 0) start = nst[last_id];
        else start = 0;

        have[start] ++ ;
        if (have[start] == need[start]) 
        {
            st[start] = true;
            int j = start;
            while (st[j]) j ++ ;
            nst[(start - 1 + n) % n] = j;
        }
        
        last_id = start;
    }

    cout << last_id + 1 << endl;
    return 0;
}
