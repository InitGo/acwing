//先用哈希表把出现的数字都存下来
//  枚举每一个小段的起始位置：如果x存在，但x-1不存在，x就是一个小段的起始位置
//  找到这个小段的结束位置：如果存在y+1，则y++且erase(y)
//  这个小段的长度就是y-x+1
//枚举过的数字都要在哈希表中erase，避免出现重复枚举
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S;

        for (int x : nums) S.insert(x);

        int res = 0;
        for (int x : nums) {
            if (S.count(x) && !S.count(x - 1)) {
                int y = x;
                S.erase(x);
                while (S.count(y + 1)) {
                    y ++ ;
                    S.erase(y);
                }
                res = max(res, y - x + 1);
            }
            
        }
        return res;
    }
};