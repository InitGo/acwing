#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e9, M = N + 1;


string dec(string &op, int l, int r)
{
    string res ;
    for (int i = l; i <= r; i ++ )
    {
        int u = op[i] - '0';
        if (u >= 2 && u <= 9)
        {
            //分解括号
            int cl = 1, cr = 0;
            int x = i + 2; //index
            while (cl != cr)
            {
                if (op[x] == '(') cl ++ ;
                else if (op[x] == ')') cr ++ ;
                x ++ ;
            }
            //计算括号内,完成字符串累加

            string substr = dec(op, i + 2, x - 2);
            while (u -- )
            {
                res += substr;
            }
            i = x - 1;
            continue;

        }
        else res += op[i];
    }

    return res;
}

int main()
{
    cin.tie(0);
    int T;
    cin >> T;

    for (int v = 1; v <= T; v ++ )
    {
        string op, res;
        cin >> op;

        res = dec(op, 0, op.size() - 1);
        
        int x = 0, y = 0;
        for (int i = 0; i < res.size(); i ++ )
        {
            char u = res[i];

            if (u == 'N') x = ((x - 1) + N ) % N;
            else if (u == 'S') x = ((x + 1) + N ) % N;
            else if (u == 'E') y = ((y + 1) + N ) % N;
            else y = ((y - 1) + N ) % N;
        }
        x = (x + 1 + M) % M;
        y = (y + 1 + M) % M;
        printf("Case #%d: %d %d\n", v, y , x);
    }

    return 0;
}