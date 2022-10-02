#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> pos;
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> in = postorder;
        sort(in.begin(), in.end());
        for (int i = 0; i < in.size(); i ++ ) pos[in[i]] = i;

        return build(postorder, in, 0, postorder.size() - 1, 0, in.size() - 1);
    }
    bool build(vector<int>& post, vector<int>& in, int pl, int pr, int il, int ir) {
        if (pl > pr) return true;
        int k = pos[post[pr]];
        if (k < il || k > ir) return false; //如果找出来的k不在inofdered的范围内,则失败
        bool letf = build(post, in, pl, pl + k - 1 - il, il, k - 1);
        bool right = build(post, in, pl + k - 1 - il + 1, pr - 1, k + 1, ir);
        return letf && right;     
    }
};