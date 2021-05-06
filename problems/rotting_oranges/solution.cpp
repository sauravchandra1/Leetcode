class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> Q;
        int r = grid.size();
        int c = grid[0].size();
        
        auto isFine = [&](int x, int y) {
            if (x >= r || x < 0 || y >= c || y < 0) return false;
            return true;
        };
        
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) Q.push({i, j});
            }
        }
        
        if (Q.empty()) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == 1) return -1;
                }
            }
            return 0;
        }
        
        while (!Q.empty()) {
            int len = Q.size();
            ans++;
            for (int p = 0; p < len; p++) {
                int x = Q.front().first, y = Q.front().second;
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (isFine(xx, yy) && grid[xx][yy] == 1) {
                        Q.push({xx, yy});
                        grid[xx][yy] = 2;
                    }
                }
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        
        return ans - 1;
    }
};