class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dx {0, 1};
        vector<int> dy {1, 0};
        auto go = [&](int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n) return false;
            return true;
        };
        vector<vector<int>> dp(m, vector<int> (n, -1));
        function<int(int, int)> dfs = [&](int x, int y) {
            if (x == m - 1 && y == n - 1) return 1;
            int &res = dp[x][y];
            if (res != -1) return res;
            res = 0;
            int xx, yy;
            for (int i = 0; i < 2; i++) {
                xx = x + dx[i];
                yy = y + dy[i];
                if (go(xx, yy)) {
                    res += dfs(xx, yy);
                }
            }
            return res;
        };
        return dfs(0, 0);
    }
};