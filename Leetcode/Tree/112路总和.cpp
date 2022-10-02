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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) return !sum; //如果是叶子节点， 判断sum

        //否则继续递归做子树
        //return root->left && hasPathSum(root->left, sum) || root->right && hasPathSum(root->right, sum);
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};