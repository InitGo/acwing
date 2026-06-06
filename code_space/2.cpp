#include <bits/stdc++.h>

using namespace std;

string s;

string path = "0123456789";

char choose(char a, char b)
{
    for (int i = 0; i < path.size(); i ++ )
        if (path[i] != a && path[i] != b)
            return path[i];
}

int main()
{
    cin >> s;
    int n = s.size();
    s = "#" + s + "#";

    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        if (s[i] == s[i - 1])
        {
            s[i] = choose(s[i - 1], s[i + 1]);
            cnt ++ ;
        }
    cout << cnt << endl;
    return
}