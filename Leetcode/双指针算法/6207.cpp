//用区间外的数字将大区间分成若干小区间
//当终点i确定，定义j为最靠近i且满足j~~i区间内包含至少一个minK和一个maxK的index
//则这段小区间的答案就是j前面的数字个数  累加

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int smax = 0, smin = 0;
        long long ans = 0;
        for (int i = 0, j = 0, last = 0; i < n; i ++ ) {
            if (nums[i] < minK || nums[i] > maxK) {
                last = j = i + 1;
                smax = smin = 0;
                continue;
            }

            if (nums[i] == maxK) smax ++ ;
            if (nums[i] == minK) smin ++ ;

            while (j < i) {
                if (nums[j] == maxK) smax -- ;
                if (nums[j] == minK) smin -- ;
                if (!smax || !smin) {
                    if (nums[j] == maxK) smax ++ ;
                    if (nums[j] == minK) smin ++ ;
                    break;
                }
                j ++ ;
            }

            if (smax && smin) {
                ans += j - last + 1;
            }
        }
        return ans;
    }
};