class Solution {
public:
    struct cmp {
        bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return (get<0>(a) > get<0>(b));      
        }
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
    int minPathSum(vector<vector<int>>& grid) {
        const int inf = 1e8;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        if (n == 1 && m == 1) return grid[0][0];
        vector<int> dx {0, 1};
        vector<int> dy {1, 0};
        auto go = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };
        pq.push(make_tuple(grid[0][0], 0, 0));
        while (!pq.empty()) {
            auto tt = pq.top();
            pq.pop();
            int d, x, y;
            tie(d, x, y) = tt;
            grid[x][y] = inf;
            for (int i = 0; i < 2; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (go(xx, yy) && grid[xx][yy] != inf) {
                    if (xx == n - 1 && yy == m - 1) return d + grid[xx][yy];
                    pq.push(make_tuple(d + grid[xx][yy], xx, yy));
                }
            }
        };
        return grid[0][0];
    }
};