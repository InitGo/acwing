class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i ++ ) {
            if (is_prime(bit_num(i))) 
                ans ++ ;
        }
        return ans;
    }

    bool is_prime(int x) {
        if (x < 2) return false;
        for (int i = 2; i <= x / i; i ++ ) {
            if (x % i == 0) 
                return false;
        }
        return true;
    }

    int bit_num(int x) {
        int ans = 0;
        while (x) {
            x -= x & -x;
            ans ++ ;
        }
        return ans;
    }
};