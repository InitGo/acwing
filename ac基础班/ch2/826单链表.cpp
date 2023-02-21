//https://www.acwing.com/activity/content/problem/content/863/
#include <iostream>
using namespace std;
const int N = 100010;

//本程序中，节点、下标、指针 表示同一概念

// head 表示头结点的下标 头部插入其他元素后，头节点的下标可能发生改变，所以头节点用变量来存
//遍历时，i 从 head --> -1
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针【下标】是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

// 初始化
void init()
{
    head = -1;//头节点【下标】指向空 定义为-1
    idx = 0; //当前用到的是 0 下标
}

// 将x插到头结点
void add_to_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx ++ ;
    // e[idx] = x;//当前可用的是idx下标，存值x
    // ne[idx]=head; //idx这个点指向下一个点为head指向的点
    // head = idx; //头节点指向新插进来的idx点
    // idx++ ; //当前可用的下标++
}

// 将x插到下标是k的点后面
void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
    // e[idx] = x;  当前可用的下标是idx，先用e[idx]存下x的值
    // ne[idx] = ne[k] ; 插进来的点的下一个指向原来的k的下一个
    // ne[k] = idx; k的指针指向idx
    // idx++; 当前可用下标++
}

// 将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];//下标是k的点的指针指向下下个
}
int main()
{
    int m;
    cin >> m;

    init();

    while (m -- )
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k) head = ne[head]; //特判一下，如果是删除0号节点，则转化为删除头节点
            else remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}
