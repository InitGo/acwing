- 算法

集合的二进制表示 $O(2^n n)$
假设集合大小是$n$，我们枚举 $0…2^n−1$，一共 $2n$ 个数。
每个数表示一个子集，假设这个数的二进制表示的第 $i$ 位是$1$，则表示该子集包含第 $i$ 个数，否则表示不包含。

另外，如果 $n≥30$，则 $2^n ≥ 10^9$，肯定会超时，所以我们可以断定 $n≤30$，可以用`int`型变量来枚举。

时间复杂度分析：一共枚举 $2^n$ 个数，每个数枚举 $n$ 位，所以总时间复杂度是 $O(2^n n)$

- 代码
```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int  n = nums.size();
        for (int i = 0; i < (1 << n); i ++ ) {
            vector<int> temp;
            for (int j = 0; j < n; j ++ ) 
                if (i >> j & 1) temp.push_back(nums[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};
```