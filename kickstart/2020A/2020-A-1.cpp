#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;

int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int num, budget;
        cin >> num >> budget;

        vector<int> a;
        for (int i = 0; i < num; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for (int item : a)
        {
            if (budget >= item)
            {
                budget -= item;
                ans++;
            }
            else
                break;
        }

        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}