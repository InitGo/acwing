- 思路：排列组合
0. 一共有n种水果
1. 统计每种水果x的个数 cnt[x]，分成m堆水果
2. 对于每种水果x，可以做的选择有：选0个/选1个/.../选cnt[x]个，共cnt[x]+1种情况
3. 把每个水果堆都选完，得到一个方案

- 时间复杂度：$O(2^n)$

- 代码1：基础写法，好理解
```c++
class Solution {
public:
    unordered_map<int, int> cnt;
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int x : nums) cnt[x] ++ ; //统计数字个数
        dfs(-10); 
        return ans;
    }
    
    void dfs(int u) {
        if (u > 10) { //数字的取值范围是-10~10，所以直接从-10开始枚举
            ans.push_back(path);
            return;
        }
        
        //有cnt[u] + 1个分支
        dfs(u + 1); //数字u一个都不选
        
        for (int i = 1; i < cnt[u] + 1; i ++ ) { //数字u选1~cnt[u]个
            for (int j = 0; j < i; j ++ ) path.push_back(u); //选i个
            dfs(u + 1); //进入下一层【选下一种水果】
            for (int j = 0; j < i; j ++ ) path.pop_back(); //pop出i个，恢复现场
        }
    }
};
```

- 代码2:进阶写法
```c++
class Solution {
public:
    unordered_map<int, int> cnt;
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (int x : nums) cnt[x] ++ ; //统计数字个数
        dfs(-10); 
        return ans;
    }
    
    void dfs(int u) {
        if (u > 10) { //数字的取值范围是-10~10，所以直接从-10开始枚举
            ans.push_back(path);
            return;
        }
        
        //有cnt[u] + 1个分支
        dfs(u + 1); //数字u一个都不选
        for (int i = 1; i < cnt[u] + 1; i ++ ) { //数字u选1~cnt[u]个
            path.push_back(u); //每添加一个就进入下一层
            dfs(u + 1);
        }
        
        //最后一起恢复现场
        for (int i = 1; i < cnt[u] + 1; i ++ ) path.pop_back();
    }
};
```