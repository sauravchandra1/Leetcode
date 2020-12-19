class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        function<int(int, int)> dfs = [&](int m, int n) {
            if (m < 0 || n < 0) return 0;
            if (m == 1 && n == 1) return 1;
            auto &res = dp[m][n];
            if (res != -1) return res;
            res = 0;
            res = dfs(m - 1, n) + dfs(m, n - 1);
            return res;
        };
        return dfs(m, n);
    }
};