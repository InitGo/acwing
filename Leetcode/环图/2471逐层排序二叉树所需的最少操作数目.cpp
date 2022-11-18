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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return 0;

        int cnt = 0;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> level;
            while (len -- ) {
                auto t = q.front();
                q.pop();
                level.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            cnt += check(level);
        }
        return cnt;
    }

    vector<int> p;
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    //数组a排成有序，需要的最少交换次数
    int check(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;
        sort(b.begin(), b.end());  //a是原数组，b是排序后的数组
        unordered_map<int, int> pos;  
        
        p.clear();  //清空并查集p数组
        for (int i = 0; i < n; i ++ ) {
            pos[a[i]] = i;  //记录原数组中每个数所在的位置
            p.push_back(i);  //初始化并查集p数组
        }

        int cnt = n;  //初始时有cnt个环/集合
        for (int i = 0; i < n; i ++ ) {
            int x = i, y = pos[b[i]];  //排序后的第i个数在原数组中处于第j个位置，则i-->j
            int px = find(x), py = find(y);
            if (px != py) {
                p[px] = py;
                cnt -- ;  //每次合并就减少一个环/集合
            }
        }
        return n - cnt;  //环图中共有cnt个环，那么最少操作n-cnt次，可变成n个环。
    }
};