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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root2) swap(root1, root2); //保证第一个参数位置优先为真
        if (!root1) return NULL;
        if (root2) root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2 ? root2->left : NULL);
        root1->right = mergeTrees(root1->right, root2 ? root2->right : NULL);
        return root1;
    }
};