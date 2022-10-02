/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (q.size()) { //q里只存一层的点
            vector<int> level; //存一层的结点的值
            int len = q.size();  //得到一层的len

            while (len -- ) {  //把这一层做完
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            res.push_back(level);
        }

        return res;
    }
};