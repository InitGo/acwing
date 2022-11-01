#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;
vector<double> ys;  //只能对y做离散化，因为离散化后的下标之间有+1的关系

struct Segment
{
    double x, y1, y2;
    int k;
    bool operator< (const Segment &t) const
    {
        return x < t.x;
    }
}seg[N * 2];

struct Node
{
    int l, r;
    //线段树[l,r]维护的是ys[r+1] ~ ys[l]的区间【重点】
    //换而言之，[l,l]的叶结点表示的区间是ys[l+1]~ys[l]
    int cnt;  //当前区间被完全覆盖的总次数
    double len;  //当前区间被部分覆盖的总长度
}tr[N * 2 * 4];

int find(double y)  //原始坐标-->离散化后的坐标
{
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();  //返回区间中第一个>=y的数字的下标
}

//modify修改cnt，pushup通过cnt计算len
void pushup(int u)
{
    if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];  //如果当前节点被覆盖次数>0[覆盖满了]，那么直接计算当前节点所表示的真实区间的长度
    //tr[u]表示离散化后的区间 [tr[u].l, tr[u].r + 1] 外面套一层ys表示真实double值

    //不是叶子节点：有孩子节点
    else if (tr[u].l != tr[u].r)  //当前节点被覆盖的次数==0[没覆盖满]，通过孩子节点计算当前区间的len
    {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else tr[u].len = 0;  //是叶子节点，则节点len为0
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1; //build函数为需要建造的区间的中点，然后递归建造
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        //新建线段树，不需要pushup
    }
}

//modify修改cnt，pushup通过cnt计算len
void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;
        pushup(u);  //多了一步pushup操作 当前Node的cnt有变化，则也会影响当前Node的len，也会pushup
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);  //当前节点的children节点发生变化，会影响当前节点，pushup
    }
}

int main()
{
    int T = 1;
    while (scanf("%d", &n), n)
    {
        ys.clear();
        for (int i = 0, j = 0; i < n; i ++ )
        {
            double x1, y1, x2, y2; //(x1, y1)是靠近坐标原点的坐标, (x2, y2)远离坐标原点的的坐标
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j ++ ] = {x1, y1, y2, 1};  //读入2n个线段 seg里存的是double坐标
            seg[j ++ ] = {x2, y1, y2, -1};
            ys.push_back(y1), ys.push_back(y2);  //所有y坐标存进ys里，待离散化
        }
        
        //对ys离散化
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        
        //离散化后纵坐标有2n个点， 2n-1个区间，构建线段树，线段树的节点维护这些区间tr[i] --> [y_i, y_i+1]，所以线段树的节点个数与区间个数相同2n-1
        build(1, 0, ys.size() - 2);  //从1号点开始建线段树，对应的离散化后的坐标的取值范围是0~ys.size()-2 --> 2n-1个

        //对线段按x排序：从左往右做
        sort(seg, seg + n * 2);

        double res = 0;
        for (int i = 0; i < n * 2; i ++ )  //依次处理每个seg
        {
            if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);  //计算答案
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);  //把当前seg作用到线段树上
            //这里一定要把实际区间 变换到 线段树表示的区间 
            //线段树的节点 维护 离散化后的区间：tr[u] --> [y_u, y_u + 1]
            //double的区间: seg[i].y1~seg[i].y2
            //离散化后的区间： find(seg[i].y1)~find(seg[i].y2)
            //线段树中的区间： find(seg[i].y1)~find(seg[i].y2)-1
        }

        printf("Test case #%d\n", T ++ );
        printf("Total explored area: %.2lf\n\n", res);
    }

    return 0;
}