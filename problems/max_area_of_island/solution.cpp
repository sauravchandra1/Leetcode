class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto go = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            if (grid[x][y] != 1) return false;
            return true;
        };
        function<int(int, int)> dfs = [&](int x, int y) {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            grid[x][y] = 0;
            int d = 0;
            while (!Q.empty()) {
                int len = Q.size();
                for (int i = 0; i < len; i++) {
                    int x = Q.front().first;
                    int y = Q.front().second;
                    Q.pop();
                    d++;
                    for (int i = 0; i < 4; i++) {
                        int _x = x + dx[i];
                        int _y = y + dy[i];
                        if (go(_x, _y)) {
                            Q.push({_x, _y});
                            grid[_x][_y] = 0;
                        }
                    }
                }
            }    
            return d;
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};