class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        int ans = 1, holder = 0;
        for (int i = 0, j = 0; i < a.size(); i ++ ) {
            while (j < i && (holder & a[i])) {
                holder = sub(holder, a[j]);
                j ++ ;
            }
            holder |= a[i];
            ans = max(ans, i - j + 1);
        }
        return ans;
    }

    int sub(int x, int y) {
        for (int i = 0; i < 31; i ++ )
            if (y >> i & 1) {
                x -= (1 << i);
            }
        return x;
    }
};