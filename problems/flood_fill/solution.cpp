class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> Q;
        int n = image.size();
        int m = 0;
        if (n > 0) m = image[0].size(); 
        vector<vector<bool>> seen(n + 1, vector<bool>(m + 1, false));
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto get = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            if (seen[x][y] == true) return false;
            else return true;
        };
        Q.push({sr, sc});
        seen[sr][sc] = true;
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; i++) {
                int _x = dx[i] + x;
                int _y = dy[i] + y;
                if (get(_x, _y) && (image[x][y] == image[_x][_y])) {
                    Q.push({_x, _y});
                    seen[_x][_y] = true;
                }
            }
            image[x][y] = newColor;
        }
        return image;
    }
};

// 1 1 1
// 1 1 0
// 1 0 1