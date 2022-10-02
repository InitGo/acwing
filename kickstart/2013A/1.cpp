#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        int n;
        int pos[N];
        memset(pos, 0, sizeof pos);

        cin >> n;
        vector<int> a, b;
        for (int i = 0; i < n; i ++ )
        {
            int x;
            cin >> x;
            if (x % 2) 
            {
                pos[i] = 1;
                a.push_back(x);
            }
            else b.push_back(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        int i = 0, j = 0, k = 0;
        while (k < n)
        {
            if (pos[k]) pos[k ++ ] = a[i ++ ];
            else pos[k ++ ] = b[j ++ ];
        }

        printf("Case #%d: ", C);
        for (int i = 0; i < n; i ++ ) cout << pos[i] << ' ';
        cout << endl;
    }
    return 0;
}

