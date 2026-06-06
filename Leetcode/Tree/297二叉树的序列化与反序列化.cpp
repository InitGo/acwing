/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs_s(TreeNode* u, string& path) {
        if (!u) {
            path += "#,";
            return;
        }
        path += to_string(u->val);
        path += ",";
        dfs_s(u->left, path);
        dfs_s(u->right, path);
    }

    TreeNode* dfs_d(string& s, int& u) {
        if (s[u] == '#') {
            u += 2;
            return NULL;
        }
        
        int j = u;                                   
        while (j < s.size() && s[j] != ',') j ++ ;
        auto node = new TreeNode(stoi(s.substr(u, j - u)));
        u = j + 1;
        node->left = dfs_d(s, u);
        node->right = dfs_d(s, u);
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string path;
        dfs_s(root, path);
        return path;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_d(data, u);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));