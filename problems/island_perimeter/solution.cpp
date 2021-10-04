class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int N = 4;
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto get = [&](int i, int j) {
            if (i >= n || j >= m || i < 0 || j < 0) return 0;
            return grid[i][j];
        };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int cnt = 0;
                    for (int l = 0; l < N; l++) {
                        int _i = dx[l] + i;
                        int _j = dy[l] + j;
                        cnt += get(_i, _j);
                    }
                    ans += N - cnt;
                }
            }
        }
        return ans;
    }
};