class Solution {
public:
    int d[2010];
    int h[2010], e[5010], ne[5010], idx;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

    vector<int> topsort(int n)
    {
        int q[2010];
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

        vector<int> ans;
        if (tt == n - 1)
            for (int i = 0; i <= tt; i ++ ) 
                ans.push_back(q[i]);
        return ans;
    }
};