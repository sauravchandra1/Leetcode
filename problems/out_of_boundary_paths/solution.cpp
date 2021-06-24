class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        const int N = 4;
        const int mod = 1e9 + 7;
        int dp[m][n][maxMove + 1];
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++)
                for (int k = 0; k < maxMove + 1; k++)
                    dp[i][j][k] = -1;
        function<int(int, int, int)> dfs = [&](int x, int y, int move) {
            if (y < 0 || y >= m || x < 0 || x >= n) return 1;
            if (move == 0) return 0;
            auto& res = dp[y][x][move];
            if (res != -1) return res;
            res = 0;
            for (int i = 0; i < N; i++) {
                int xx = dx[i] + x;
                int yy = dy[i] + y;
                res = (res % mod + dfs(xx, yy, move - 1)) % mod;
            }
            return res;
        };
        return dfs(startColumn, startRow, maxMove);
    }
};