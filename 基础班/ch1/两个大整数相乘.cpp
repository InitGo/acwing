class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size(), m = num2.size();

        for (int i = n - 1; ~i; i -- ) A.push_back(num1[i] - '0');
        for (int i = m - 1; ~i; i -- ) B.push_back(num2[i] - '0');

        vector<int> C(n + m);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                C[i + j] += A[i] * B[j];

            
        vector<int> res;
        for (int i = 0, t = 0; i < C.size() ; i ++ ) {
            t += C[i];
            res.push_back(t % 10);
            t /= 10;
        }

        while (res.size() > 1 && res.back() == 0) res.pop_back();

        string str;
        for (int i = res.size() - 1; ~i; i -- ) str += char(res[i] + '0');
        return str;
    }
};