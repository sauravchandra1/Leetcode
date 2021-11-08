class Solution {
public:
    int numTrees(int N) {
        vector<int> dp(N + 1, -1);
        function<int(int)> dfs = [&](int n) {
            if (n <= 1) return 1;
            auto& res = dp[n];
            if (res != -1) return res;
            res = 0;
            for (int i = 1; i <= n; i++) 
                res += dfs(i - 1) * dfs(n - i);
            return res;
        };
        return dfs(N);
    }
};