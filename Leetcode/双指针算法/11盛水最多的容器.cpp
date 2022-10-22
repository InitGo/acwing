class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j;) {
            ans = max(ans, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) i ++ ;
            else j -- ;
        }
        return ans;
    }
};