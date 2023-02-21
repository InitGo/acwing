#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    sort(a, a + n);
    
    long long res = 0;
    for (int i = 0; i < n; i ++ ) res += a[i] * (n - 1 - i);
    
    cout << res << endl;
    return 0;
}