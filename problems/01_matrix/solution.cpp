class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) Q.push({i, j});
                else mat[i][j] = -1;
            }
        }
        const int N = 4;
        vector<int> dx {0, 1, 0 ,-1};
        vector<int> dy {1, 0, -1, 0};
        auto isFine = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };
        int d = 0;
        while (!Q.empty()) {
            int len = Q.size();
            d++;
            for (int l = 0; l < len; l++) {
                auto p = Q.front();
                Q.pop();
                int x = p.first, y = p.second;
                for (int i = 0; i < N; i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (isFine(xx, yy) && mat[xx][yy] == -1) {
                        mat[xx][yy] = d;
                        Q.push({xx, yy});
                    }
                }
            }
        }
        return mat;
    }
};