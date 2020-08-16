class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int> (n, -1));
        sort(coins.begin(), coins.end());
        function<int(int, int)> dfs = [&](int val, int idx) {
            if (val == 0) return 1;
            if (idx == n) return 0;
            auto &res = dp[val][idx];
            if (res != -1) return res;
            res = 0;
            for (int i = idx; i < n; i++) {
                if (coins[i] > val) break;
                res += dfs(val - coins[i], i);
            }
            return res;
        };
        return dfs(amount, 0);
    }
};