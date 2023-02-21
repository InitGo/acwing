#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;

int n;
int q[N];

//估价函数
//如果估价函数=0，说明不存在逆序后继,全部排好序了，即找到终点
int f()
{
    int cnt = 0;
    for (int i = 0; i + 1 < n; i ++ )
        if (q[i + 1] != q[i] + 1)
            cnt ++ ;
    return (cnt + 2) / 3;
}


//也可以用check函数判断是否找到终点
bool check()
{
    for (int i = 0; i + 1 < n; i ++ )
        if (q[i + 1] != q[i] + 1)
            return false;
    return true;
}

bool dfs(int depth, int max_depth) //当前层数，层数上限-->当前走了depth步,最多走max_depth步
{
    if (depth + f() > max_depth) return false;  //如果当前层数+估价函数>层数上限,剪枝
    if (!f()) return true;  //找到合法方案 返回true

    for (int len = 1; len <= n; len ++ )  //枚举长度
        for (int l = 0; l + len - 1 < n; l ++ )  //枚举线段左端点
        {
            int r = l + len - 1;  //线段右端点
            for (int k = r + 1; k < n; k ++ )  //往前搜有等价的,只需要往后搜
            {
                int w[N];
                memcpy(w, q, sizeof q);  //先先存下来q状态到 w,方便恢复现场
                int x, y;
                //交换逻辑
                for (x = r + 1, y = l; x <= k; x ++, y ++ ) q[y] = w[x];
                for (x = l; x <= r; x ++, y ++ ) q[y] = w[x];
                if (dfs(depth + 1, max_depth)) return true;
                memcpy(q, w, sizeof q);  //恢复现场
            }
        }

    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> q[i];

        int max_depth = 0;
        while (max_depth < 5 && !dfs(0, max_depth)) max_depth ++ ;  //最多走4步,起始位置走了0步 可以走1, 2, 3, 4步
        if (max_depth >= 5) puts("5 or more");
        else cout << max_depth << endl;
    }

    return 0;
}