class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx >= len) return 0;
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 0;
            res = min(dfs(idx + 1), dfs(idx + 2)) + cost[idx];
            return res;
        };
        int ans = min(dfs(0), dfs(1));
        return ans;
    }
};