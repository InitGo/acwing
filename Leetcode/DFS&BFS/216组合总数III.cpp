class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, 0, n);
        return ans;
    }

    void dfs(int u, int k, int sum, int n) {
        if (path.size() > k) return;
        if (sum > n) return;
        if (u == 10) {
            if (path.size() == k && sum == n) ans.push_back(path);
            return;
        }

        for (int i = 0; i <= 1; i ++ ) {
            dfs(u + 1, k, sum + i * u, n);
            path.push_back(u);
        }

        for (int i = 0; i <= 1; i ++ ) path.pop_back();
    }
};