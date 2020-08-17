class Solution {
    public:
        int Count(vector < string > & board, char c) {
            int cnt = 0;
            for (auto x: board) {
                for (auto y: x) {
                    if (y == c)
                        cnt++;
                }
            }
            return cnt;
        }
    bool isMatch(vector < string > & board, char c) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][1] == board[i][0] && board[i][1] == board[i][2] && board[i][0] == c)
                return true;
            if (board[1][i] == board[0][i] && board[1][i] == board[2][i] && board[1][i] == c)
                return true;
        }
        if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[0][0] == c)
            return true;
        if (board[1][1] == board[2][0] && board[1][1] == board[0][2] && board[1][1] == c)
            return true;
        return false;
    }
    bool validTicTacToe(vector < string > & board) {
        int x = Count(board, 'X');
        int y = Count(board, 'O');
        if (y > x)
            return false;
        if (x - y > 1)
            return false;
        bool a = isMatch(board, 'X');
        bool b = isMatch(board, 'O');

        /*
        XXX
        XOO
        OO-
        
        
        OXX
        XOX
        OXO
        */

        if (a && b) return false;
        if (a && x == y) return false;
        if (b && x > y) return false;
        return true;

    }
};