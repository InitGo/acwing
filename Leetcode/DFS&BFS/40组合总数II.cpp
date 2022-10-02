class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    unordered_map<int, int> cnt;
    vector<int> nums;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (int x : candidates) cnt[x] ++ ;
        for (auto t : cnt) nums.push_back(t.first);
        
        dfs(0, 0, target);
        return ans;
    }

    void dfs(int u, int sum, int target) {
        if (sum > target) return;
        if (u == nums.size()) {
            if (sum == target) ans.push_back(path);
            return;
        }

        for (int i = 0; i <= cnt[nums[u]]; i ++ ) {
            dfs(u + 1, sum + i * nums[u], target);
            path.push_back(nums[u]);
        }
        
        for (int i = 0; i <= cnt[nums[u]]; i ++ ) path.pop_back();
    }
};