class Solution {
public:
    double myPow(double x, int n) {
        typedef long long LL;
        bool is_minus = n < 0;
        double res = 1;
        for (LL k = abs(LL(n)); k; k >>= 1) {
            if (k & 1) res *= x;
            x *= x;
        }
        if (is_minus) res = 1 / res;
        return res;
    }
};