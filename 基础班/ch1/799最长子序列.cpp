//https://www.acwing.com/activity/content/problem/content/833/

#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], s[N];
//q读入给出的数串，s标记每个数出现的次数  
//下标-->数字本体 值-->出现的次数 s【数字】=出现的次数

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    int res = 0;//res保存结果
    for (int i = 0, j = 0; i < n; i ++ )
    {
        //i往后移动了一格，q[i]的出现次数+1
        s[q[i]] ++ ; 

        //如果子串中有重复的数，那一定是新加进来的q[i]，所以只要 q[i]出现的次数-->s[q[i]] 还大于1，就一直移动j
        //j每次往后移动一格，出去一个j指向的数字，s[q[j++]]--       
        while (j < i && s[q[i]] > 1) s[q[j ++ ]] -- ; 

         
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}
