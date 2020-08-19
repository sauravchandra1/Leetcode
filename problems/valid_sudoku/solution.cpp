class MySet {
    unsigned int set = 0;
    public:
        bool insert(char val) {
            unsigned int mask = 1 << val; 
            if (mask & set) return true;
            set |= mask;
            return false;
        }
};

class Solution {
    public:
        bool isValidSudoku(vector < vector < char >> & board) {
            MySet rows[9], columns[9], grid[3][3];
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') continue;
                    board[i][j] -= '0';
                    if (rows[i].insert(board[i][j])) return false;
                    if (columns[j].insert(board[i][j])) return false;
                    if (grid[i / 3][j / 3].insert(board[i][j])) return false;
                }
            return true;
        }
};