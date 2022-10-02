#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int k, n, m, sx, sy;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
unordered_map<char, int> OP;

struct pair_hash
{
    template<class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const
    {
        auto h1 = hash<T1> {}(p.first);
        auto h2 = hash<T2> {}(p.second);
        return h1 ^ h2;
    }
};

unordered_map<PII, bool, pair_hash> st;

void init()
{
    OP['N'] = 0, OP['E'] = 1, OP['S'] = 2, OP['W'] = 3;
}

int main()
{
    init();

    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        st.clear();
        string str;
        cin >> k >> n >> m >> sx >> sy >> str;
        st[{sx, sy}] = true;

        for (int i = 0; i < k; i ++ )
        {
            char c = str[i];
            int biasx = dx[OP[c]], biasy = dy[OP[c]];
            int a = sx + biasx, b = sy + biasy;
            while (st[{a, b}])
            {
                a += biasx, b += biasy;
            } 

            st[{a, b}] = true;
            sx = a, sy = b;
        }

        printf("Case #%d: %d %d\n", C, sx, sy);
    }
    return 0;
}