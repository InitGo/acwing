#include <bits/stdc++.h>

using namespace std;

bool big(string& a, string& b)
{
    for (int i = 0; i < min(a.size(), b.size()); i ++ )
        if (a[i] != b[i])
            return a[i] > b[i];
    if (a.size() < b.size()) return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    string s;
    while (T -- )
    {
        cin >> s;
        int n = s.size();
        bool flag = false;
        for (int i = 0; i < n - 1; i ++ )
        {
            for (int j = i + 1; j < n - 1; j ++ )
            {
                string a = s.substr(0, i + 1), 
                b = s.substr(i + 1, j - i), 
                c = s.substr(j + 1);

                if ((big(b, a) && big(b, c)) || (big(a, b) && big(c, b)))
                {
                    cout << a  << ' ' << b << ' ' << c << endl;
                    flag = true;
                    break;
                }
                
            }
            if (flag) break;
        }

        if (!flag) cout << ":(" << endl;
    }
    return 0;
}
