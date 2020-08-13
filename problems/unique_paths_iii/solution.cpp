class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        int cnt = 0;
        pair<int, int> p;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int v = grid[i][j];
                if (v == 0) cnt++;
                if (v == 1) {
                    p.first = i;
                    p.second = j;
                }
            }
        }
        auto get = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            else return true;
        };
        function<int(int, int, int)> dfs = [&](int x, int y, int c) {
            if (get(x, y) == false) return 0;
            if (grid[x][y] == 2) {
                if (c - 1 == cnt) return 1;
                return 0;
            } 
            if (grid[x][y] == -1) return 0;
            int res = 0;
            grid[x][y] = -1;
            for (int i = 0; i < 4; i++) {
                res += dfs(x + dx[i], y + dy[i], c + 1);
            }
            grid[x][y] = 0;
            return res;
        };
        return dfs(p.first, p.second, 0);
    }
};