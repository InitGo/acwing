class Solution {
public:
    vector<string> ans;

    void dfs(string path, int left, int u, int n)
    {
        if (u == n)
        {
            if (!left) ans.push_back(path);
            return;
        }
        if (left)
        {
            dfs(path + ')', left - 1, u + 1, n);
        }
        dfs(path + '(', left + 1, u + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n * 2);
        return ans;
    }
};