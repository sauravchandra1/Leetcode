class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = 0;
        if (n) m = grid[0].size();
        int c = 0;
        auto valid = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            else return true;
        };
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{1, 0, -1, 0};
        const int N = 4;
        function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = '#';
            int xx, yy;
            for (int i = 0; i < N; i++) {
                xx = dx[i] + x;
                yy = dy[i] + y;
                if (valid(xx, yy) && grid[xx][yy] == '1') {
                    dfs(xx, yy);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    c++;
                    dfs(i, j);
                }
            }
        }
        return c;
    }
};