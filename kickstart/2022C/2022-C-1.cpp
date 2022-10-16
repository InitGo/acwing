#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
string p;

int main()
{
    int T;
    cin >> T;
    char sp[] = {'#', '@', '*', '&',};
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        cin >> p;
        bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
        for (int i = 0; i < n; i ++ )
        {
            char c = p[i];
            if (c >= 'A' && c <= 'Z') flag1 = true; 
            if (c >= 'a' && c <= 'z') flag2 = true;
            if (c >= '0' && c <= '9') flag3 = true;
            for (int k = 0; k < 4; k ++ )
                if (c == sp[k])
                    flag4 = true;
        }

        if (!flag1) p += 'A';
        if (!flag2) p += 'a';
        if (!flag3) p += '0';
        if (!flag4) p += '#';

        while (p.size() < 7) p += '0';
        
        cout << "Case #" << C << ": " << p << endl;

    }
    return 0;
}