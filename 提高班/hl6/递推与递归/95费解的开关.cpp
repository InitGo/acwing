#include <iostream>
#include <cstring>

using namespace std;

const int N = 6;

string g[N], bg[N];
int dx[] = {-1, 0, 1, 0, 0}, dy[] = {0, 1, 0, -1, 0};

void turn(int x, int y)
{
    for (int i = 0; i < 5; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) continue;
        if (g[a][b] == '1') g[a][b] = '0';
        else g[a][b] = '1';
    }
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        for (int i = 0; i < 5; i ++ ) cin >> bg[i];

        int res = 10;
        for (int op = 0; op < 32; op ++ )
        {
            int cnt = 0;
            //memcpy(g, bg, sizeof g); string不能用memcpy复制
            for (int i = 0; i < 5; i ++ ) g[i] = bg[i];
            // 操作第一行的开关
            for (int i = 0; i < 5; i ++ )
                if (op >> i & 1)
                {
                    turn(0, i);
                    cnt ++ ;
                }

            // 递推出第1~4行开关的状态
            for (int i = 0; i < 4; i ++ )
                for (int j = 0; j < 5; j ++ )
                    if (g[i][j] == '0')
                    {
                        turn(i + 1, j);
                        cnt ++ ;
                    }

            // 检查最后一行灯是否全亮
            bool success = true;
            for (int i = 0; i < 5; i ++ )
                if (g[4][i] == '0')
                    success = false;
            if (success && res > cnt) res = cnt;
        }

        if (res > 6) res = -1;
        cout << res << endl;
    }

    return 0;
}