#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int h[N], e[N], ne[N], idx;
string name[N];
vector<string> ans;

void add(int a, int b, string& namea, string& nameb)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    name[a] = namea, name[b] = nameb;
}

void get_name(int u, int pa) 
{
    int cnt = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j != pa) 
        {
            cnt ++ ;
            get_name(j, u);
        }
    }
    if (cnt > 1) ans.push_back(name[u]);
}

int main()
{
    memset(h, -1, sizeof h);
    
    get_name(1, -1);
}