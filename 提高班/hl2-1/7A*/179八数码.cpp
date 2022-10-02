#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

//heap的第一维需要存 当前距离真实值+估价距离 用于优化搜索空间
//第二维 存其他信息 & 当前点的真实距离，用于维护最短距离问题


//估价函数：曼哈顿距离：每个点最少走多少步才能到目标位置
int f(string state)
{
    int res = 0;
    for (int i = 0; i < state.size(); i ++ )
        if (state[i] != 'x')
        {
            int t = state[i] - '1';  //获取当前字符
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);  //计算当前字符t从当前位置(i/3, i%3)走到正确位置(t/3, t%3)需要的步数
        }
    return res;
}


//二维坐标转一维
int get(int x, int y)
{
    return x * 3 + y;
}

string bfs(string start)
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};  //上右下左 方向
    char op[4] = {'u', 'r', 'd', 'l'};  //对应的option

    string end = "12345678x"; //目标状态
    unordered_map<string, int> dist;  //距离
    unordered_map<string, pair<string, char>> prev;  //存方案 ： 当前序列 ： 前一个序列，操作
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;  //{估价函数，序列状态}

    dist[start] = 0;
    heap.push({f(start) + dist[start], start});
    
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        string state = t.second;
        if (state == end) break;  //终点第一次出队时，是最短距离

        int step = dist[state];
        int x, y;  //存空格的二维坐标
        for (int i = 0; i < state.size(); i ++ )  //找空格
            if (state[i] == 'x') 
            {
                x = i / 3, y = i % 3;  //转换成二维坐标
                break;
            }
        
        //state每次操作后都会改变，用source存下来，方便恢复现场
        string source = state;
        for (int i = 0; i < 4; i ++ )  //扩展优先队列，四个方向
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
          
            state = source;
            swap(state[get(x, y)], state[get(a, b)]);
            if (!dist.count(state) || dist[state] > step + 1)  //如果这个状态之前没扩展过或者新扩展的距离小于上一次扩展的距离，则更新
            {
                dist[state] = step + 1;  //上一次距离 + 1
                prev[state] = {source, op[i]};  //存方案
                heap.push({dist[state] + f(state), state});  //入堆
            }     
        }
    }

    //处理方案
    string res;
    while (end != start)
    {
        res += prev[end].second;
        end = prev[end].first;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string g, c, seq;  //g存初始状态序列，seq存没有x的序列
    while (cin >> c)
    {
        g += c;
        if (c != "x") seq += c;
    }

    //计算逆序对
    int t = 0;
    for (int i = 0; i < seq.size(); i ++ )
        for (int j = i + 1; j < seq.size(); j ++ )
            if (seq[i] > seq[j])
                t ++ ;

    if (t % 2) puts("unsolvable");
    else cout << bfs(g) << endl;

    return 0;
}