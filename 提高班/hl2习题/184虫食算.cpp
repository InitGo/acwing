#include <cstring>
#include <iostream>
#include <algorithm>
//#include <time.h>

using namespace std;

const int N = 30;

int n;
//char eq[3][N];
string eq[3];
int q[N], path[N];
bool st[N];

bool check()
{
    for (int i = n - 1, t = 0; i >= 0; i -- )
    {
        int a = path[eq[0][i] - 'A'], b = path[eq[1][i] - 'A'], c = path[eq[2][i] - 'A'];
        if (a != -1 && b != -1 && c != -1)
        {
            if (t == -1)
            {
                if ((a + b) % n != c && (a + b + 1) % n != c) return false;
                if (!i && a + b >= n) return false; // 最高位有进位
            }
            else
            {
                if ((a + b + t) % n != c) return false;
                if (!i && a + b + t >= n) return false;
                t = (a + b + t) / n;
            }
        }
        else t = -1;
    }

    return true;
}

bool dfs(int u)
{
    if (u == n) return true;

    for (int i = 0; i < n; i ++ )
        if (!st[i])
        {
            st[i] = true;
            path[q[u]] = i;
            if (check() && dfs(u + 1)) return true;
            path[q[u]] = -1;
            st[i] = false;
        }

    return false;
}

int main()
{
    //clock_t start, end;//定义clock_t变量
    //start = clock();
    cin >> n >> eq[0] >> eq[1] >> eq[2];

    for (int i = n - 1, k = 0; i >= 0; i -- )
        for (int j = 0; j < 3; j ++ )
        {
            int c = eq[j][i] - 'A';
            if (!st[c])
            {
                st[c] = true;
                q[k ++ ] = c;
            }
        }

    memset(st, 0, sizeof st);
    memset(path, -1, sizeof path);

    dfs(0);

    for (int i = 0; i < n; i ++ ) cout << path[i] << ' ';
    //cout << endl;
    //end = clock();
    //cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;  //输出时间（单位：ｓ）
    return 0;
}

/*这组数据，用string会TLE
18
FQAGNMBECLPOJDHIKR
ADQGABEHFDQADOKPML
LOCOLJFGIRMGJKQCDH
*/