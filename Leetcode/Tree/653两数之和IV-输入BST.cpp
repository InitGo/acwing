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
    vector<int> a;
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        //有序数组找两数之和，双指针
        for (int i = 0, j = a.size() - 1; i < j; i ++ ) {
            while (i < j && a[i] + a[j] > k) j -- ;
            if (i < j && a[i] + a[j] == k) return true;
        }
        return false;
    }
    
    //BST做中序遍历，有序数组
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    }

};