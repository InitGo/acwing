#include <bits/stdc++.h>

using namespace std;

unordered_map<string, pair<char, string>> pre; //记录方案， key是由value.second经过操作value.first走到的
unordered_map<string, int> dist; //从起点start走到 状态为string的点，的最短距离

string translate(char ch, string s) 
{
    if (ch == 'A') return {s[7], s[6], s[5], s[4], s[3], s[2], s[1], s[0]};
    else if (ch == 'B') return {s[3], s[0], s[1], s[2], s[5], s[6], s[7], s[4]};
    else if (ch == 'C') return {s[0], s[6], s[1], s[3], s[4], s[2], s[5], s[7]};
    return "[Error]: Invalid 'ch' argument.";
}

int bfs(string start, string end)
{
    if (start == end) return 0;

    queue<string> q;
    q.push(start);
    dist[start] = 0;


    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 3; i ++ )
        {
            char choose = 'A' + i; //
            string ne = translate(choose, t);
            if (!dist.count(ne)) //map中key = ne的元素 存在/不存在 返回1/0
            {
                dist[ne] = dist[t] + 1;
                pre[ne] = {choose, t};
                q.push(ne);
                if (ne == end) return dist[end];
            }
        }
    }

    return -1;
}

int main()
{
    int x;
    string start, end;
    for (int i = 0; i < 8; i ++ ) //读入目标状态end
    {
        cin >> x;
        end += char(x + '0');
    }

    for (int i = 1; i <= 8; i ++ ) start += char('0' + i); //初始化起始状态start

    int step = bfs(start, end); //做bfs返回最短距离

    cout << step << endl;

    //输出转移路径
    string res;
    while (end != start)
    {
        res += pre[end].first; //end是由谁转移过来的，操作是啥：pre[end].first
        end = pre[end].second; //end是由谁转移过来的，具体string是啥：pre[end].second
    }

    reverse(res.begin(), res.end());

    if (step > 0) cout << res << endl;

    return 0;
}
