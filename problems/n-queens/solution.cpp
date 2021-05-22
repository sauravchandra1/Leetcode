class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                board[i] += '.';
        vector<vector<string>> ans;
        auto isSafe = [&](int i, int j) {
            int x = i, y = j;
            //Check Left Diagonal
            while (x >= 0 && y >= 0) {
                if (board[x][y] != '.') return false;
                x--, y--;
            }
            //Check Right Diagonal
            x = i, y = j;
            while (x >= 0 && y < n) {
                if (board[x][y] != '.') return false;
                x--, y++;
            }
            //Check Column
            x = i, y = j;
            while (x >= 0) {
                if (board[x][y] != '.') return false;
                x--;
            }
            return true;
        };
        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                ans.push_back(board);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (isSafe(row, j)) {
                    board[row][j] = 'Q';
                    dfs(row + 1);
                    board[row][j] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};