class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool> (m, false));
        auto go = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            if (seen[x][y] == true || grid[x][y] == 0) return false;
            return true;
        };
        function<int(int, int)> dfs = [&](int x, int y) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    seen[i][j] = false;
                }
            }
            queue<pair<int, int>> Q;
            Q.push({x, y});
            int d = 0;
            seen[x][y] = true;
            pair<int, int> p;
            while (!Q.empty()) {
                int len = Q.size();
                d++;
                for (int i = 0; i < len; i++) {
                    p = Q.front();
                    int x = p.first;
                    int y = p.second;
                    Q.pop();
                    for (int j = 0; j < 4; j++) {
                        int xx = x + dx[j];
                        int yy = y + dy[j];
                        if (go(xx, yy)) {
                            if (grid[xx][yy] == 2) return d;
                            if (grid[xx][yy] == 1) {
                                seen[xx][yy] = true;
                                Q.push({xx, yy});
                            }   
                        }
                    }
                }
            }
            return -1;
        };
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int res = dfs(i, j);
                    if (res == -1) return res;
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        if (ans == INT_MIN) return 0;
        return ans;
    }
};