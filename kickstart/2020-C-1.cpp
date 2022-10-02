#include <iostream>

using namespace std;

const int N = 200010;

int a[N];

int main()
{
    cin.tie(0);

    int T;
    cin >> T;

    for (int v = 1; v <= T; v ++ )
    {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; i ++ ) cin >> a[i];

        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            if (a[i] == k)
            {
                int j = i, tag = k;
                while (tag != 0 && j < n && a[j] == tag)
                {
                    j ++ ;
                    tag -- ;
                }

                if (tag == 0) res ++ ;
                i = j - 1;
            }
        }

        printf("Case #%d: %d\n", v, res);
    }

    return 0;
}