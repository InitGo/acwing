#include <iostream>
#include <cstring>

using namespace std;

const int N = 200010;

int n;
string str;
int f[N];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n >> str;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i ++ )
        {
            if (str[i - 1] == '0') f[i] = f[i - 1];
            else f[i] = f[i - 1] + 2;
        }
        cout << f[n] << endl;
    }
    return 0;
}