class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(2, vector<int>(m, 1));
        for (int i = 1; i < n; i++) 
            for (int j = 1; j < m; j++)  
                dp[i & 1][j] = dp[i & 1][j - 1] + dp[!(i & 1)][j];
        return dp[(n - 1) & 1][m - 1];
    }
};