#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {1, 3, 5, 9, 7, 6, 2, 4, 8};

    sort(a, a + 9, [](const int& x, const int& y) {
        if ((x % 2) != (y % 2))
            return (x % 2) > (y % 2);
        if (x != y) return x <= y;
        return false;
    });

    for (int i = 0; i < 9; i ++ )
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}