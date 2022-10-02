#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 21;

int n;
string word[N];
int g[N][N]; //二维矩阵，单词index之间可以接上的的最小值是多少
int used[N]; //记录每个单词使用次数
int ans;

void dfs(string dragon, int last)
{
    ans = max((int)dragon.size(), ans);

    used[last] ++ ;

    for (int i = 0; i < n; i ++ )
        if (g[last][i] && used[i] < 2)
            dfs(dragon + word[i].substr(g[last][i]), i);

    used[last] -- ;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> word[i]; //读入单词
    char start;
    cin >> start;

    //预处理， 记录每个单词index后面可以接哪个index，接的长度是多少
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
        {
            string a = word[i], b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); k ++ )
                if (a.substr(a.size() - k, k) == b.substr(0, k))
                {
                    g[i][j] = k;
                    break;
                }
        }

    for (int i = 0; i < n; i ++ )
        if (word[i][0] == start)
            dfs(word[i], i);

    cout << ans << endl;

    return 0;
}