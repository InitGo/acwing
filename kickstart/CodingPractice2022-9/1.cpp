#include <iostream>

using namespace std;

int n, m;

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n >> m;
        int sum = 0;
        while (n -- )
        {
            int x;
            cin >> x;
            sum += x;
        }
        printf("Case #%d: %d\n", C, sum % m);
    }
    return 0;
}