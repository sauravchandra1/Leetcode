class Solution {
public:
    Solution() {ios_base::sync_with_stdio(false); cin.tie(NULL);}
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{1, 0, -1, 0};
        int n = board.size(), m = board[0].size();
        auto valid = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            else return true;
        };
        const int N = 4;
        vector<vector<bool>> seen(n, vector<bool> (m, false));
        bool res = false;
        function<bool(int, int, int)> get = [&](int x, int y, int idx) {
            if (res) return res;
            seen[x][y] = true;
            if (idx == word.size()) return (res = true);
            int xx, yy;
            for (int i = 0; i < N; i++) {
                xx = dx[i] + x;
                yy = dy[i] + y;
                if (valid(xx, yy) && (board[xx][yy] == word[idx]) && !seen[xx][yy]) {
                    res = (res || get(xx, yy, idx + 1));
                    seen[xx][yy] = false;
                }
            }
            return res;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) get(i, j, 1);
                if (res) return res;
                seen[i][j] = false;
            }
        }
        return res;
    }
};