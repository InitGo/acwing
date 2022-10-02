class Solution {
public:
    int n;

    //分别构建行和列的拓扑序，二者相互独立
    vector<int> topsort(vector<vector<int>>& es) {
        vector<vector<int>> g(n + 1);
        vector<int> d(n + 1);

        for (auto& e: es) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            d[b] ++ ;
        }

        queue<int> q;
        for (int i = 1; i <= n; i ++ )
            if (!d[i])
                q.push(i);

        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (int u: g[t])
                if ( -- d[u] == 0)
                    q.push(u);
        }

        return res;
    }

    int get(vector<int>& w, int x) {
        for (int i = 0; i < n; i ++ )
            if (w[i] == x)
                return i;
        return -1;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        n = k;
        auto row = topsort(rowConditions);
        auto col = topsort(colConditions);
        if (row.size() < n || col.size() < n) return {};
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 1; i <= n; i ++ )
            res[get(row, i)][get(col, i)] = i;
        return res;
    }
};