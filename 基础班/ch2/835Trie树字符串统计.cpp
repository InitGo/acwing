//https://www.acwing.com/activity/content/problem/content/883/
#include <iostream>
using namespace std;

const int N = 100010;
//算法题中用到trie树，一定会限制出现的字符种类，方便定义子节点的最大维数
//本题中说明只有小写字母，每个节点最多只有26个子节点 son[N][26]存子节点
//cnt存 以当前节点结尾的 字符串个数
//idx存当前用到了哪个下标，下标是0的点，既是根节点，又是空节点
int son[N][26], cnt[N], idx;


void insert(string str)
{
    int p = 0;//从根节点开始
    //遍历整个字符串，c++中字符串结尾是\0，作为循环判断条件
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a'; //计算 当前字母对应的子节点编号 映射为0~25
        if (!son[p][u]) son[p][u] = ++ idx; //如果p不存在u这个儿子【son[p][u]是0】，创建出来，给他分配下标
        p = son[p][u]; //走到下一个节点
    }
    cnt[p] ++ ; //字符串完成插入后，让这个点上的字符串数量++
}
//返回字符串出现多少次
int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0; //不存在子节点，返回0
        p = son[p][u]; //存在就继续走
    }
    return cnt[p]; //返回以p结尾的单词数量
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n -- )
    {
        string op,str;
        cin >> op >> str;
        if (op == "I") insert(str);
        else printf("%d\n", query(str));
    }

    return 0;
}
