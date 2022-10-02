/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//如果一棵二叉树和它的镜像一样，那么它是对称的。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return is_same(root->left, root->right);
    }

    bool is_same(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return is_same(p->left, q->right) && is_same(p->right, q->left);
    }
};