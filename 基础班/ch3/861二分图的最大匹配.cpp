//https://www.acwing.com/activity/content/problem/content/927/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m; //n1,n2分别是两个点集的点的个数
int h[N], e[M], ne[M], idx;
int match[N];//match[j]=a,表示小猫j的现有配对主人是a
bool st[N]; //st[]数组我称为临时预定数组，st[j]=a表示一轮模拟匹配中，小猫j被主人a预定了。

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//这个函数的作用是用来判断,如果加入x来参与模拟配对,会不会使匹配数增多
bool find(int x)
{
    //遍历x喜欢的小猫
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])//如果在这一轮模拟匹配中,这个小猫尚未被预定
        {
            st[j] = true;//那x就预定这个小猫了
            //如果小猫j没有主人，或者她原来的主人能够预定其它小猫。配对成功,更新match
            if (match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    //自己中意的全部都被预定了。配对失败。
    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b); 
        //存边只存一边就行了，虽然是无向图。
        //存每个主人喜欢的小猫
    }
    
    //记录最大匹配
    int res = 0;
    for (int i = 1; i <= n1; i ++ )
    {
        //因为每次模拟匹配的预定情况都是不一样的所以每轮模拟都要初始化
        memset(st, false, sizeof st);
        if (find(i)) res ++ ;
    }

    printf("%d\n", res);

    return 0;
}