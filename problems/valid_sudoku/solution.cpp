class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> se;
        const int N = 9;
        // Row checking
        for (int i = 0; i < N; i++) {
            se.clear();
            for (int j = 0; j < N; j++) {
                auto ch = board[i][j];
                if (ch >= '0' && ch <= '9') {
                    if (se.count(ch) > 0) return false;
                    se.insert(ch);
                }
            }
        }
        // Column checking
        for (int j = 0; j < N; j++) {
            se.clear();
            for (int i = 0; i < N; i++) {
                auto ch = board[i][j];
                if (ch >= '0' && ch <= '9') {
                    if (se.count(ch) > 0) return false;
                    se.insert(ch);
                }
            }
        }
        // Sub-boxes checking
        for (int br = 0; br < N; br += 3) {
            for (int bc = 0; bc < N; bc += 3) {
                se.clear();
                for (int i = br; i < br + 3; i++) {
                    for (int j = bc; j < bc + 3; j++) {
                        auto ch = board[i][j];
                        if (ch >= '0' && ch <= '9') {
                            if (se.count(ch) > 0) return false;
                            se.insert(ch);
                        }
                    }
                }
            }
        }
        return true;
    }
};