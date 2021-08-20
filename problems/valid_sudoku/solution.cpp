class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        vector<int> visited(N);
        auto check = [&]() {
            for (int i = 0; i < N; i++) if (visited[i] > 1) return false;
            return true;
        };
        for (int i = 0; i < N; i++) {
            visited.assign(N, 0);
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') continue;
                visited[board[i][j] - '0' - 1]++;
            }
            if (!check()) return false;
        }
        for (int j = 0; j < N; j++) {
            visited.assign(N, 0);
            for (int i = 0; i < N; i++) {
                if (board[i][j] == '.') continue;
                visited[board[i][j] - '0' - 1]++;
            }
            if (!check()) return false;
        }
        for (int i = 0; i < N; i += 3) {
            for (int j = 0; j < N; j += 3) {
                visited.assign(N, 0);
                for (int l = 0; l < 3; l++) {
                    for (int r = 0; r < 3; r++) {
                        if (board[i + l][j + r] == '.') continue;
                        visited[board[i + l][j + r] - '0' - 1]++;
                    }
                }
                if (!check()) return false;
            }
        }
        return true;
    }
};