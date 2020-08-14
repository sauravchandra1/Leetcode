class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<tuple<int, int, int>> Q;
        tuple<int, int, int> tt;
        get<0>(tt) = 0;
        get<1>(tt) = 0,
        get<2>(tt) = 0;
        Q.push(tt);
        vector<int> dx {0, 1, 0, -1, 1, 1, -1, -1};
        vector<int> dy {1, 0, -1, 0, 1, -1, 1, -1};
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        const int N = 8;
        int d, x, y;
        auto gett = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= n) return false;
            if (grid[x][y] != 0) return false;
            return true;
        };
        int ans = INT_MAX;
        while (!Q.empty()) {
            tt = Q.front();
            Q.pop();
            tie(d, x, y)  = tt;
            if (x == n - 1 && y == n - 1) {
                ans = min(ans, d);
                continue;
            }
            grid[x][y] = 1;
            for (int i = 0; i < N; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (gett(xx, yy)) {
                    grid[xx][yy] = 1;
                    get<0>(tt) = d + 1;
                    get<1>(tt) = xx;
                    get<2>(tt) = yy;
                    Q.push(tt);
                }
            }
        }
        if (ans == INT_MAX) return -1;
        return ans + 1;
        /*
        1 0 0
        1 1 0
        1 1 0
        */
    }
};