class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        const int N = 9;
        vector<vector<int>> row(N, vector<int>(N)), col(N, vector<int>(N)), box(N, vector<int>(N));
        
        auto Set = [&](int i, int j, int val) {
            int b = 3 * (i / 3) + (j / 3);
            row[i][val] = col[j][val] = box[b][val] = 1;
            board[i][j] = val + '0' + 1;
        };
        
        auto Unset = [&](int i, int j, int val) {
            int b = 3 * (i / 3) + (j / 3);
            row[i][val] = col[j][val] = box[b][val] = 0;
            board[i][j] = '.';
        };
        
        auto isSafe = [&](int i, int j, int val) {
            int b = 3 * (i / 3) + (j / 3);
            if (row[i][val] || col[j][val] || box[b][val]) return false;
            return true;
        };
        
        auto get = [&](int i, int j) {
            return (board[i][j] - '0' - 1);
        };
        
        function<bool(int, int)> dfs = [&](int r, int c) {
            if (r == N) return true;
            for (int i = r; i < N; i++) {
                for (int j = c; j < N; j++) {
                    c = 0;
                    if (board[i][j] != '.') continue;
                    else {
                        for (int v = 0; v < N; v++) {
                            if (!isSafe(i, j, v)) continue;
                            Set(i, j, v);
                            if (j == N - 1) {
                                if (dfs(i + 1, 0)) return true;
                            }
                            else {
                                if (dfs(i, j + 1)) return true;
                            }
                            Unset(i, j, v);
                        }
                        return false;
                    }
                }
            }
            return true;
        };
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                if (board[i][j] != '.') Set(i, j, get(i, j));
        dfs(0, 0);
    }
};