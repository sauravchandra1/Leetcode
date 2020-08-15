class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const long long mod = 1e9 + 7;
        if (d * f < target) return 0;
        vector<vector<long long>> dp(d + 1, vector<long long>(target + 1, -1));
        function<long long(int, int)> dfs = [&](int d, int t) {
            if (d == 0 && t == 0) return 1LL;
            else if (d == 0) return 0LL;
            auto &ans = dp[d][t];
            if (ans != -1) return ans;
            ans = 0;
            for (int i = 1; i <= f; i++) {
                if (i > t) return ans;
                ans += dfs(d - 1, t - i);
                ans %= mod;
            }
            return ans;
        };
        int ans = dfs(d, target);
        return ans;
    }
};