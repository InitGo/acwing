//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution {
public:
    vector<int> path;
    vector<bool> st;
    vector<vector<int>> ans;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //先排序，保证相同的数字在一起
        st = vector<bool>(nums.size(), false);  //初始化st和path数组
        path = vector<int>(nums.size());
        dfs(nums, 0);
        return ans;
    }   

    void dfs(vector<int>& nums, int u)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i ++ )
        {
            if (st[i]) continue;  //第i个数被用过了，continue
            if (i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
            //i不是第一个数 && 当前数与前一个数相等 && 前一个数没有被用过 则这个数不能用

            path[u] = nums[i];
            st[i] = true;
            dfs(nums, u + 1);
            st[i] = false;
        }
    }
};