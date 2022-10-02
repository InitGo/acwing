/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* t) {  //dfs(t)返回以t为根的子树的最大深度，全局变量ans存枚举每个点作为顶点，能得到的路径的最大值
        if (!t) return 0;
        int left = dfs(t->left), right = dfs(t->right);
        ans = max(ans, left + right);  //左右两边的最大值相加，就是穿过当前点的最大路径
        return max(left, right) + 1;
    }
};