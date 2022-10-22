class Solution {
public:
    int calc(vector<int>& A, int limit) {
        int res = 0;
        for (int i = 0; i < A.size(); i ++ ) {
            if (A[i] > limit) continue;
            int j = i + 1;
            while (j < A.size() && A[j] <= limit) j ++ ;
            int k = j - i;
            res += (long long)k * (k + 1) / 2;
            i = j;
        }
        return res;
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return calc(A, R) - calc(A, L - 1);
    }
};