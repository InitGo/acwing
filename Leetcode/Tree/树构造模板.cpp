// 根据数组构造二叉树
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    // 把输入数值数组，先转化为二叉树节点数组
    for (int i = 0; i < vec.size(); i ++ ) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]); // 用 -1 表示null
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    // 遍历一遍，根据规则左右孩子赋值就可以了
    // 注意这里 结束规则是 i * 2 + 2 < vec.size()，避免空指针
    for (int i = 0; i * 2 + 2 < vec.size(); i ++ ) {
        if (vecTree[i] != NULL) {
            // 线性存储转链式存储关键逻辑
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (p->val > q->val) swap(p, q);
        if (root->val >= p->val && root->val <= q->val) return root;
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
}

int main()
{
    vector<int> vec = {6,2,8,0,4,7,9,-1,-1,3,5};

    auto root = construct_binary_tree(vec);
    auto p = new TreeNode(2), q = new TreeNode(8);

    auto ans = lowestCommonAncestor(root, p, q);
    if (ans) cout << ans->val << endl;
    else cout << "NULL" << endl;

    return 0;
}