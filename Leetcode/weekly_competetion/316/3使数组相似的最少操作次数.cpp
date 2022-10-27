class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& cost) {
        typedef long long LL;
        typedef pair<int, int> PII;
        int n = a.size();
        
        vector<PII> all;
        for (int i = 0; i < n; i ++ ) all.push_back({a[i], cost[i]});
        sort(all.begin(), all.end());

        LL cnt = 0;
        for (int i = 0; i < n; i ++ ) cnt += cost[i];

        LL get = cnt / 2;
        int target;
        for (auto t : all) {
            get -= t.second;
            if (get <= 0) {
                target = t.first;
                break;
            }
        }

        LL res = 0;
        for (auto t : all) {
            res += abs(t.first - target) * (LL)t.second;
        }
        return res;
    }
};