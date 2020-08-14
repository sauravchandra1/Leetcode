class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> nums;
        if (forest[0][0] == 0) return -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto v = forest[i][j];
                if (v > 1) {
                    nums.push_back(v);
                    mp[v] = make_pair(i, j);
                }
            }
        }
        sort(nums.begin(), nums.end());
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto go = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            if (forest[x][y] == 0) return false;
            return true;
        };
        function<int(int, int, int, int)> dfs = [&](int x, int y, int xx, int yy) {
            if (x == xx && y == yy) {
                return 0;
            }
            queue<pair<int, int>> Q;
            vector<vector<bool>> seen(n, vector<bool> (m, false));
            pair<int, int> tt;
            int d = 0;
            tt.first = x;
            tt.second = y;
            Q.push(tt);
            seen[x][y] = true;
            int _x, _y;
            while (!Q.empty()) {
                d++;
                int _size = Q.size();
                for (int j = 0; j < _size; j++) {
                    tt = Q.front();
                    Q.pop();
                    x = tt.first;
                    y = tt.second;
                    for (int i = 0; i < 4; i++) {
                        _x = x + dx[i];
                        _y = y + dy[i];
                        if (_x == xx && _y == yy) {
                            return d;
                        }
                        if (go(_x, _y) && !seen[_x][_y]) {
                            Q.push(make_pair(_x, _y));
                            seen[_x][_y] = true;
                        }
                    }
                }
            }
            return -1;
        };
        int ans = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++) {
            int xx = mp[nums[i]].first;
            int yy = mp[nums[i]].second;
            int ok = dfs(x, y, xx, yy);
            if (ok < 0) {
                return ok;
            }
            ans += ok;
            x = xx;
            y = yy;
        }
        return ans;
    }
};