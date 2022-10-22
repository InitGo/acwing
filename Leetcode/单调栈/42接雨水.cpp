class Solution {
public:
    int trap(vector<int>& h) {
        stack<int> stk;
        int res = 0, last = 0;
        for (int i = 0; i < h.size(); i ++ ) {
            while (stk.size() && h[i] >= h[stk.top()]) {
                res += (i - stk.top() - 1) * (h[stk.top()] - last);
                last = h[stk.top()];
                stk.pop();
            }

            if (stk.size()) res += (i - stk.top() - 1) * (h[i] - last);
            stk.push(i);
        }
        return res;
    }
};