#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map> //哈希存字符串

using namespace std;

const int N = 6;

int n;
string A, B;
string a[N], b[N];

//扩展是为了求出所有能到的点
//步数记录了扩展次数，每一步都判断是否有相遇，如果相遇，则当前步数就是最短次数

//扩展？ 扩展队列！取出队头string t，应用规则，找到队头t走一步可以走到哪些状态，扩展queue
//参数：要扩展的队列是哪个， 当前队列的dist数组，另一个队列的dist数组， 目标是要把字符串a转化成字符串b
//返回本次扩展的结果：如果扩展过程中会师了，就返回距离，没有会师，就返回非法值，表示本次扩展暂时无解
int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, 
    string a[N], string b[N])
{
    int d = da[q.front()];  //每次应该扩展一层：把所有和当前队列的队首元素在同一层的点全部扩展出来：同一层的距离相等，用距离判断
    while (q.size() && da[q.front()] == d)
    {
        auto t = q.front();
        q.pop();
        
        //枚举规则  扩展的起点-扩展的规则 两个维度
        for (int i = 0; i < n; i ++ ) //枚举规则
            for (int j = 0; j < t.size(); j ++ ) //枚举起点
                if (t.substr(j, a[i].size()) == a[i]) //从j开始的，长度是a[i]这么长的一段子串，是不是规则希望的字符串 
                {
                    string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size()); //变换后：t的前半段(0~j-1)+规则变换后(b[i])+后半段(j+a[i].size()~结尾)
                    
                    //判断是否与db重合
                    if (db.count(r)) return da[t] + db[r] + 1; //如果b已经扩展到了r，走到重合处了
                    if (da.count(r)) continue; //判断这个状态是不是被a扩展过了，不是才加入队列
                    da[r] = da[t] + 1;
                    q.push(r);
                }
    }

    //当前队列扩展完一层以后没有与另一个队列重合的结果，没有搜到结果，返回非法值
    return 11; //当前扩展的方向没有和另一个方向重合，返回11
}

int bfs()
{
    if (A == B) return 0;
    queue<string> qa, qb; //建两个方向的队列，qa从起点开始搜，qb从终点开始搜
    unordered_map<string, int> da, db; //记录每个状态到起点/终点的距离

    qa.push(A), qb.push(B);
    da[A] = db[B] = 0;

    int step = 0;
    while (qa.size() && qb.size()) //qa和qb都有值的时候才可以继续做扩展，如果其中一个扩展完了，说明两个状态不连通
    {
        int t;  //t作为本次扩展的结果标识
        if (qa.size() <= qb.size()) t = extend(qa, da, db, a, b);  //注意这里用小于等于
        else t = extend(qb, db, da, b, a);

        if (t <= 10) return t;  //如果找到了，返回距离
        if ( ++ step == 10) return -1;  //累计扩展次数大于等于10了，还没找到解，返回no solution
    }

    return -1;
}

int main()
{
    cin >> A >> B;
    while (cin >> a[n] >> b[n]) n ++ ;

    int t = bfs();
    if (t == -1) puts("NO ANSWER!");
    else cout << t << endl;

    return 0;
}