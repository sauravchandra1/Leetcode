class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int inf = 1e9;
        vector<int> dp(amount + 1, -1);
        function<int(int)> dfs = [&](int amount) {
            if (amount < 0) return inf;
            if (amount == 0) return 0;
            auto& res = dp[amount];
            if (res != -1) return res;
            res = inf;
            for (int i = 0; i < n; i++) {
                res = min(res, dfs(amount - coins[i]) + 1);
            }
            return res;
        };
        int ans = dfs(amount);
        if (ans == inf) ans = -1;
        return ans;
    }
};