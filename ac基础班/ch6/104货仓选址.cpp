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
    
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += abs(a[i] - a[n / 2]); //a[n / 2]是中位数
    
    cout << res << endl;
    return 0;
}