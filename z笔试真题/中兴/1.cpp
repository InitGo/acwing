#include <bits/stdc++.h>

using namespace std;

const int N = 6;

int n, m;
set<int> priority;
int a[N], b[N];

int main()
{
    cin >> n >> m;
    while (n -- )
    {
        int x;
        cin >> x;
        a[x] ++ ;
    }

    for (int i = 0; i < m; i ++ ) cin >> b[i];
    for (int i = 0; i < m; i ++ )
    {
        int x = b[i];
        for (int j = 0; j < a[x]; j ++ ) cout << x << ' ';
        priority.insert(x);
    }

    for (int i = 0; i < n; i ++ )
    {
        if (!a[i] || priority.count(i)) continue;
        for (int k = 0; k < a[i]; k ++ ) cout << i << ' ';
    }
    return 0;
}

/*
5 3
5 4 3 2 1
3 5 4
*/