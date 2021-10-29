class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        const int N = 4;
        auto get = [&](int x, int y) {
            if (x >= n || x < 0 || y >= m || y < 0) return false;
            return true;
        };
        queue<pair<int, int>> Q;
        int d = 0;
        auto dfs = [&]() {
            while (!Q.empty()) {
                int len = Q.size();
                d++;
                for (int i = 0; i < len; i++) {
                    int x = Q.front().first, y = Q.front().second;
                    Q.pop();
                    for (int l = 0; l < N; l++) {
                        int xx = x + dx[l];
                        int yy = y + dy[l];
                        if (get(xx, yy) && grid[xx][yy] == 1) {
                            grid[xx][yy] = 2;
                            Q.push({xx, yy});
                        }
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == 2) Q.push({i, j});
        dfs();
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) return -1;
        return max(0, d - 1);
    }
};