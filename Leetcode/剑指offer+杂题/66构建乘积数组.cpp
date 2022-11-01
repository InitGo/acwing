class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty()) return vector<int>(0);

        int n = a.size();
        vector<int> b(n);
        for (int i = 0, p = 1; i < n; i ++ ) {
            b[i] = p;
            p *= a[i];
        }
        for (int i = n - 1, p = 1; i >= 0; i -- ) {
            b[i] *= p;
            p *= a[i];
        }
        return b;
    }
};