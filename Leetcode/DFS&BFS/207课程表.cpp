class Solution {
public:
    int d[100010];
    int h[100010], e[5010], ne[5010], idx;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h, -1, sizeof h);
        for (auto t: prerequisites)
        {
            add(t[1], t[0]);
            d[t[0]] ++ ;
        }

        return topsort(numCourses);
    }

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }

    bool topsort(int n)
    {
        int q[100010];
        int hh = 0, tt = -1;
        for (int i = 0; i < n; i ++ )
            if (d[i] == 0)
                q[ ++ tt] = i;
        
        while (hh <= tt)
        {
            int t = q[hh ++ ];
            for (int i = h[t]; ~i; i = ne[i])
            {
                int j = e[i];
                d[j] -- ;
                if (d[j] == 0) q[ ++ tt] = j;
            }
        }

        return tt == n - 1;
    }
};