#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        for (int i = 0; i < n; i ++ )
        {
            int x;
            cin >> x;
            cnt += x;
        }
        printf("Case #%d: %d\n", C, cnt % m);
    }
    return 0;
}