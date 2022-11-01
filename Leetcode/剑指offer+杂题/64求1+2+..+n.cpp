class Solution {
public:
    int sumNums(int n) {
        int res = n;
        //if (n > 0) res += sumNums(n - 1);
        n > 0 && (res += sumNums(n - 1));
        return res;
    }
};