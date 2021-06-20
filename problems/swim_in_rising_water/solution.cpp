class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int N = 4;
        const int inf = 1e9;
        
        int n = grid.size();
        
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, inf));
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        auto isFine = [&](int i, int j) {
            if (i < 0 || i >= n || j < 0 || j >= n) return false;
            return true;
        };
        
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int x = p.second.first, y = p.second.second;
            if (visited[x][y]) continue;
            if (x == n - 1 && y == n - 1) return dist[x][y];
            visited[x][y] = true;
            for (int i = 0; i < N; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (isFine(xx, yy) && !visited[xx][yy] && 
                    dist[xx][yy] > max(dist[x][y], grid[xx][yy])) {
                    dist[xx][yy] = max(dist[x][y], grid[xx][yy]);
                    pq.push({dist[xx][yy], {xx, yy}});
                }
            }
        }
        return 0;
    }
};