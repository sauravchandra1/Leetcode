class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> start;
        int count = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) count++;
                if (grid[i][j] == 1) { start.first = i; start.second = j; }
            }
        }
        const int N = 4;
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto get = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };
        int ans = 0;
        function<void(int, int, int)> dfs = [&](int x, int y, int d) {
            if (grid[x][y] == -1) return;
            if (grid[x][y] == 2) {
                if (count == d) ans++;
                return;
            }
            grid[x][y] = -1;
            for (int i = 0; i < N; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (get(xx, yy)) dfs(xx, yy, d + 1);
            }
            grid[x][y] = 0;
        };
        grid[start.first][start.second] = 0;
        dfs(start.first, start.second, 0);
        return ans;
    }
};