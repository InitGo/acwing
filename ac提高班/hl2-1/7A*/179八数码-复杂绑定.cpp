#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, string>> PIIS;

const int N = 12;

unordered_map<string, int> dist;
unordered_map<string, pair<string, char>> pre;

int get(int x, int y)
{
    return x * 3 + y;
}

int f(string& s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i ++ )
        if (s[i] != 'x')
        {
            int t = s[i] - '1';
            cnt += abs(t/3 - i/3) + abs(t%3 - i%3);  //应该的位置(t/3,t%3), 目前的位置(i/3, i%3);
        }
    return cnt;
}

string astar(string start)
{
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    string op = "urdl";
    
    string stop = "12345678x";
    
    dist[start] = 0;
    priority_queue<PIIS, vector<PIIS>, greater<PIIS>> heap;
    heap.push({0 + f(start), {0, start}});
    
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        string str = t.second.second;
        int step = t.second.first;
        if (str == stop) break;
        
        string backup = str;
        int x, y;
        for (int i = 0; i < str.size(); i ++ )
            if (str[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
        
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            
            string ths = backup;
            swap(ths[get(x, y)], ths[get(a, b)]);
            if (!dist.count(ths) || dist[ths] > dist[backup] + 1)
            {
                dist[ths] = dist[backup] + 1;
                heap.push({f(ths) + dist[ths], {dist[ths], ths}});
                pre[ths] = {backup, op[i]};
            }
        }
    }
    
    string res;
    string ths = stop;
    while (ths != start)
    {
        res += pre[ths].second;
        ths = pre[ths].first;
    }
    
    reverse(res.begin(), res.end());
    return res;
    
}

int main()
{
    string g, c, seq;
    while (cin >> c)
    {
        g += c;
        if (c != "x") seq += c;
    }
    
    int cnt = 0;
    for (int i = 0; i < seq.size(); i ++ )
        for (int j = i + 1; j < seq.size(); j ++ )
            if (seq[i] > seq[j])
                cnt ++ ;
    
    if (cnt % 2) cout << "unsolvable" << endl;
    else cout << astar(g) << endl;
    
    return 0;
}