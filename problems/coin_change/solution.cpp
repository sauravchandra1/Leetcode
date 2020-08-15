class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int inf = 1e8;
        vector<int> dp(amount + 1, -1);
        sort(coins.begin(), coins.end());
        function<int(int)> dfs = [&](int val) {
            if (val == 0) return 0;
            auto &ans = dp[val];
            if (ans != -1) return ans;
            ans = inf;
            for (int i = 0; i < n; i++) {
                if (coins[i] > val) {
                    return ans;   
                }
                ans = min(ans, dfs(val - coins[i]) + 1);
            }
            return ans;
        };
        int ans = dfs(amount);
        if (ans == inf) return -1;
        return ans;
    }
};