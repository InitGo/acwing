#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int cnt[N];

int main()
{

    while (cin >> a[n]) n ++ ;

    for (int i = 0; i < n; i ++ ) cnt[a[i]] ++ ;

    sort(cnt, cnt + n);
    reverse(cnt, cnt + n);

    int num = 0, res = 0;
    for (int i = 0; i < n; i ++ )
    {
        if (res >= n / 2) break;
        res += cnt[i];
        num ++ ;
    }
    cout << num << endl;

    return 0;
}

//2 2 5 5 6 7 7 7