class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = 3;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (N, -1));
        /* 
        State 0 -> Cooldown
        State 1 -> Buy
        State 2 -> Sell
        */
        function<int(int, int)> dfs = [&](int idx, int state) {
            if (idx == n) return 0;
            auto &res = dp[idx][state];
            if (res != -1) return res;
            if (state == 1) {
                int a = dfs(idx + 1, 1);
                int b = dfs(idx + 1, 2) + prices[idx];
                res = max(a, b);
            } else if (state == 2) {
                int a = dfs(idx + 1, 0);
                res = max(0, a);
            } else {
                int a = dfs(idx + 1, 1) - prices[idx];
                int b = dfs(idx + 1, 0);
                res = max(a, b);
            }
            return res;
        };
        return max(0, dfs(0, 0));
    }
};