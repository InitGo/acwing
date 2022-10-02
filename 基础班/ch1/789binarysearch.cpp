#include <iostream>

using namespace std;

const int N = 100010;

int n, q;
int a[N];

int bs1(int x, int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bs2(int x, int l, int r)
{
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    
    while (q -- )
    {
        int x;
        cin >> x;
        int l = bs1(x, 0, n - 1);
        if (a[l] != x)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        else
        {
            int r = bs2(x, 0, n - 1);
            cout << l << ' ' << r << endl;   
        }
    }
    return 0;
}