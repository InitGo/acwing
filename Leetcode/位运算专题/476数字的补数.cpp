class Solution {
public:
    int findComplement(int num) {
        if (!num) return 1;
        int cnt = 0;
        for (int x = num; x; x >>= 1) //求数字的位数cnt，其最高位必定是1
            cnt ++ ;

        return ~num & ((1ll << cnt) - 1); //只对后cnt-1位取反
        //x可能是31位的，cnt=31， 1 << 31会溢出， 所以用long long 类型的1
    }
};