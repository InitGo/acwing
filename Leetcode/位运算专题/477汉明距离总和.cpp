class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 31; i ++ ) {
            int x = 0, y = 0;
            for (int c : nums) {
                if (c >> i & 1) x ++ ;
                else y ++ ;
            }
            res += x * y;
        }
        return res;
    }
};