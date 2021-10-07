class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        const int N = 4;
        int ll;
        auto get = [&](int x, int y) {
            if (x >= n || x < 0 || y >= m || y < 0 || board[x][y] != word[ll]) 
                return false;
            return true;
        };
        function<bool(int, int, int)> dfs = [&](int r, int c, int l) {
            if (l == word.size()) return true;
            for (int i = 0; i < N; i++) {
                int x = dx[i] + r;
                int y = dy[i] + c;
                ll = l;
                if (get(x, y)) {
                    board[x][y] = '.';
                    if (dfs(x, y, l + 1)) return true;
                    board[x][y] = word[l];
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    if (dfs(i, j, 1)) return true;
                    board[i][j] = word[0];
                }
            }
        return false;   
    }
};