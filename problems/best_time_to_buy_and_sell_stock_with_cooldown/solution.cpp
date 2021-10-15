class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(len, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx >= len - 1) return 0;
            auto& res = dp[idx];
            if (res != -1) return res;
            res = 0;
            for (int i = idx + 1; i < len; i++) {
                if (prices[i] > prices[idx]) 
                    res = max(res, prices[i] - prices[idx] + dfs(i + 2));
                res = max(res, dfs(i));
            }
            return res;
        };
        return dfs(0);
    }
};