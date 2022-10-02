#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int main()
{
    int T;
    cin >> T;
    
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n >> x >> y;
        int sum = (1 + n) * n / 2;
        int ratio = x + y;
        if (sum % ratio == 0)
        {
            //cout << "Case #" << C << ": " << "POSSIBLE" << endl;
            int tag = sum / ratio * x;
            if (tag <= n)
            {
                cout << "Case #" << C << ": " << "POSSIBLE" << endl;
                cout << 1 << endl;
                cout << tag << endl;
            }
            else
            {
                vector<int> ans;
                for (int k = n; k >= 1; k -- )
                {
                    if (tag == 0) break;
                    if (k <= tag)
                    {
                        ans.push_back(k);
                        tag -= k;
                    }
                }
                if (tag != 0)
                    cout << "Case #" << C << ": " << "IMPOSSIBLE" << endl;
                else
                {
                    cout << "Case #" << C << ": " << "POSSIBLE" << endl;
                    cout << ans.size() << endl;
                    for (int a : ans)
                        cout << a << ' ';
                    cout << endl;
                }

            }
        }
        else
            cout << "Case #" << C << ": " << "IMPOSSIBLE" << endl;

    }
    return 0;
}