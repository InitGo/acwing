class Solution {
public:
    int sum;
    int len;
    int edge[4]; //四个框子装火柴
    bool makesquare(vector<int>& matchsticks) {
        for (int x : matchsticks) sum += x;
        if (sum % 4) return false;
        len = sum / 4;
        sort(matchsticks.begin(), matchsticks.end());
        reverse(matchsticks.begin(), matchsticks.end());
        return dfs(matchsticks, 0, 0);
    }
    //正在处理第u个火柴，已经有s个框子装满了
    bool dfs(vector<int>& matchsticks, int u, int s) {
        if (u == matchsticks.size()) { //火柴处理完了
            if (s == 4) return true; //如果有4个框子装好，true
            else return false;
        }

        for (int i = 0; i < 4; i ++ ) { //枚举u可以放进哪个框子
            if (edge[i] < len && edge[i] + matchsticks[u] <= len) {
                edge[i] += matchsticks[u];
                if (dfs(matchsticks, u + 1, s + (edge[i] == len))) return true;;
                edge[i] -= matchsticks[u];
            }
        }
        return false;
    }
};