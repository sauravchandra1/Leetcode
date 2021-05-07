class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        
        const int N = 4;
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        
        auto isFine = [&](int x, int y) {
            if (x >= r || x < 0 || y >= c || y < 0) return false;
            else return true;
        };
        
        function<void(int, int)> dfs = [&](int x, int y) {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            grid[x][y] = '0';
            while (!Q.empty()) {
                int x = Q.front().first, y = Q.front().second;
                Q.pop();
                for (int i = 0; i < N; i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (isFine(xx, yy) && grid[xx][yy] == '1') {
                        Q.push({xx, yy});
                        grid[xx][yy] = '0';
                    }
                }

            }
        };
        
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};