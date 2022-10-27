class Solution {
public:
    struct Node {
        int l, r, v;
    }tr[4010];

    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    void pushup(Node& u, Node& l, Node& r) {
        u.v = gcd(l.v, r.v);
    }

    void pushup(int u) {
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, vector<int>& a) {
        if (l == r) tr[u] = {l, r, a[l - 1]};
        else
        {
            tr[u] = {l, r};
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, a), build(u << 1 | 1, mid + 1, r, a);
            pushup(u);
        }
    }

    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l > mid) return query(u << 1 | 1, l, r);
        else if (r <= mid) return query(u << 1, l, r);
        else{
            Node res;
            Node left = query(u << 1, l, r);
            Node right = query(u << 1 | 1, l, r);
            pushup(res, left, right);
            return res;
        }
    }

    int subarrayGCD(vector<int>& a, int k) {
        int n = a.size();
        build(1, 1, n, a);

        int ans = 0;
        for (int i = 1; i <= n; i ++ )
            for (int j = i; j <= n; j ++ )
                if (query(1, i, j).v == k)
                    ans ++ ;

        return ans;
    }
};