#include <iostream>

using namespace std;

const int N = 110;

int n;
int path[N];

bool dfs(int u, int depth)  //u表示当前层数，depth表示最大层数
{
    if (u == depth)
    {
        return path[u - 1] == n;
    }
    
    bool st[N] = {0};
    for (int i = u - 1; ~i; i -- )
        for (int j = i; ~j; j -- )
        {
            int s = path[i] + path[j];
            if (s > n || s <= path[u - 1] || st[s]) continue;  //这里剪枝一定要注意，枚举第u个位置的值时，符合题意的才能加进来
            
            st[s] = true;  //st不是现场状态的一部分，只是用于排除重复节点
            path[u] = s;
            if (dfs(u + 1, depth)) return true;
        }
    return false;
}

int main()
{
    while (cin >> n, n)
    {
        path[0] = 1;  //
        int max_depth = 1;  //max_depth表示搜索的层数，也表示path数组内元素个数cnt  max_depth表示加成序列长度的上限
        while (!dfs(1, max_depth)) max_depth ++ ; //起始位置的加成序列长度为 1, 上限为max_depth
        
        for (int i = 0; i < max_depth; i ++ )
            cout << path[i] << ' ';
        cout << endl;
    }
    return 0;
}