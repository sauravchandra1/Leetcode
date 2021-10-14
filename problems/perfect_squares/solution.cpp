class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        const int inf = 1e9;
        function<int(int)> dfs = [&](int n) {
            if (n == 0) return 0;
            auto& res = dp[n];
            if (res != -1) return res;
            res = inf;
            for (int i = 1; n >= i * i; i++) {
                int a = dfs(n - i * i) + 1;
                res = min(res, a);
            }
            return res;
        };
        return dfs(n);
    }
};