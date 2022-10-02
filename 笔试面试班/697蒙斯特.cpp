#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        int n;
        cin >> n;
        vector<string> g;

        string str;
        getline(cin, str);
        for (int i = 0; i < n; i++)
        {
            getline(cin, str);
            g.push_back(str);
        }

        int cnt = 0;
        int ths = 0;
        for (int i = 1; i < g.size(); i++)
        {
            if (g[i] < g[ths])
                cnt++;
            else
                ths = i;
        }
        printf("Case #%d: %d\n", C, cnt);
    }
    return 0;
}