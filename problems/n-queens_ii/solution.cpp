class Solution {
    public:
    char matrix[10][10];
    int ans = 0;
    bool isSafe(int row, int col, int n) {
        for (int i = row; i >= 0; i--) {
            if (matrix[i][col] == 'Q')
                return false;
        }
        int i = row, j = col;
        while (i < n && j < n && ~i && ~j) {
            if (matrix[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row, j = col;
        while (i < n && j < n && ~i && ~j) {
            if (matrix[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void nQueen(int n, int row) {
        if (row == n) {
            ans++;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n)) {
                matrix[row][col] = 'Q';
                nQueen(n, row + 1);
                matrix[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        nQueen(n, 0);
        return ans;

    }
};