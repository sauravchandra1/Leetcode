class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> Q;
        int ans = 0;
        auto isFine = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m) return false;
            return true;
        };
        vector<int> dx {1, 0, -1, 0};
        vector<int> dy {0, 1, 0, -1};
        const int N = 4;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    Q.push({i, j});
                    grid[i][j] = 0;
                    int res = 0;
                    while (!Q.empty()) {
                        int x = Q.front().first, y = Q.front().second;
                        res++;
                        Q.pop();
                        for (int k = 0; k < N; k++) {
                            int _x = x + dx[k];
                            int _y = y + dy[k];
                            if (isFine(_x, _y) && grid[_x][_y] == 1) {
                                Q.push({_x, _y});
                                grid[_x][_y] = 0;
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};