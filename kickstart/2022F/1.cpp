#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
struct Node
{
    string color;
    int d, id;
}node1[N], node2[N];

bool cmp1(Node& a, Node& b)
{
    if (a.color != b.color) return a.color < b.color;
    return a.id < b.id;
}

bool cmp2(Node& a, Node& b)
{
    if (a.d != b.d) return a.d < b.d;
    return a.id < b.id;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            string color;
            int d, id;
            cin >> color >> d >> id;
            node1[i] = {color, d, id};
            node2[i] = {color, d, id};
        }
        sort(node1, node1 + n, cmp1);
        sort(node2, node2 + n, cmp2);

        int cnt = 0;
        for (int i = 0; i < n; i ++ )
            if (node1[i].id == node2[i].id)
                cnt ++ ;
        printf("Case #%d: %d\n", C, cnt);
    }
    return 0;
}