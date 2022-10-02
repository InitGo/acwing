class Solution {
public:
    const int N = 210, mod = 1e9 + 7;
    vector<int> ys;
    
    struct Segment
    {
        int x, y1, y2, k;
        bool operator< (const Segment& t) const
        {
            return x < t.x;
        }
    }seg[210 * 2];

    struct Node
    {
        int l, r;
        int cnt, len;
    }tr[210 * 8];

    int find(int y)
    {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    }

    void pushup(int u)
    {
        if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
        else if (tr[u].l != tr[u].r)
        {
            tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
        }
        else tr[u].len = 0;
    }

    void build(int u, int l, int r)
    {
        if (l == r) tr[u] = {l, r, 0, 0};
        else
        {
            tr[u] = {l, r};
            int mid = l + r >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        }
    }

    void modify(int u, int l, int r, int k)
    {
        if (tr[u].l >= l && tr[u].r <= r) 
        {
            tr[u].cnt += k;
            pushup(u);
        }
        else
        {
            int mid = tr[u].l + tr[u].r >> 1;
            if (l <= mid) modify(u << 1, l, r, k);
            if (r > mid) modify(u << 1 | 1, l, r, k);
            pushup(u);
        }
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        for (int i = 0, j = 0; i < n; i ++ )
        {
            auto t = rectangles[i];
            seg[j ++ ] = {t[0], t[1], t[3], 1};
            seg[j ++ ] = {t[2], t[1], t[3], -1};
            ys.push_back(t[1]), ys.push_back(t[3]);
        }

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        build(1, 0, ys.size() - 2);

        sort(seg, seg + 2 * n);
        long long res = 0;
        for (int i = 0; i < 2 * n; i ++ )
        {
            if (i) res = (res + tr[1].len * (long long)(seg[i].x - seg[i - 1].x)) % mod;
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }

        return (int)res;
    }
};