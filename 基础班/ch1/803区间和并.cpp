//https://www.acwing.com/activity/content/problem/content/837/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs)
{
    vector<PII> res;//定义答案

    sort(segs.begin(), segs.end()); //排序

    int st = -2e9, ed = -2e9; //定义初始情况，当前维护区间为负无穷到负无穷
    for (auto seg : segs)
        if (ed < seg.first) //找到了新的
        {
            if (st != -2e9) res.push_back({st, ed}); //判断一下，不是初始情况，就把当前维护的区间要放进结果res里【退役了新的区间要登场】
            st = seg.first, ed = seg.second; //更新当前维护区间
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed}); //最后，把当前维护的区间也加入进res里

    segs = res;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<PII> segs;
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }

    merge(segs);

    cout << segs.size() << endl;

    return 0;
}