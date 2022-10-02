#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++ )
    {
        string I, P;
        cin >> I >> P;

        int len1 = I.size(), len2 = P.size();

        if(len1 > len2)
        {
            printf("Case #%d: IMPOSSIBLE\n", i);
            continue;
        }

        int res = 0;
        int j = 0, k = 0;
        for (; j < len1 && k < len2;)
        {
            while (I[j] != P[k])
            {
                k ++;
                res ++;
            }
            j ++ ;
            k ++ ;
        }

        if (j==len1 && k == len2)
        {
            printf("Case #%d: %d\n", i, res);
        }
        else
        {
            printf("Case #%d: IMPOSSIBLE\n", i);
        }

    }
    return 0;
}
