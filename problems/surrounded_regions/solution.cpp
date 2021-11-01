class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        const int N = 4;
        vector<int> dx {0, 1, 0, -1};
        vector<int> dy {1, 0, -1, 0};
        auto get = [&](int x, int y) {
            if (x < 0 || x >= n || y < 0 || y >= m) return false;
            return true;
        };
        auto mark = [&](int x, int y) {
            queue<pair<int, int>> Q;
            board[x][y] = '#';
            Q.push({x, y});
            while (!Q.empty()) {
                int x = Q.front().first, y = Q.front().second;
                Q.pop();
                for (int i = 0; i < N; i++) {
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    if (get(xx, yy) && board[xx][yy] == 'O') {
                        board[xx][yy] = '#';
                        Q.push({xx, yy});
                    }
                }
            }
        };
        int i, j;
        i = 0;
        while (i < n) {
            if (board[i][0] == 'O') mark(i, 0);
            i++;
        }
        i = 0;
        while (i < n) {
            if (board[i][m - 1] == 'O') mark(i, m - 1);
            i++;
        }
        j = 0;
        while (j < m) {
            if (board[0][j] == 'O') mark(0, j);
            j++;
        }
        j = 0;
        while (j < m) {
            if (board[n - 1][j] == 'O') mark(n - 1, j);
            j++;
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == '#') board[i][j] = 'O';
    }
};