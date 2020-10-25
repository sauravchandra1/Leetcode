class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        function<int(int, int)> dfs = [&](int x, int state) {
            if (x == 1) return 1;
            if (x <= 0) return 0;
            auto& res = dp[x][state];
            if (res != -1) return res;
            for (int i = 1; x >= i * i; i++) {
                res = max(1 - dfs(x - i * i, 1 - state), res);
                if (res == 1) break;
            }   
            return res;
        };
        int res = dfs(n, 0);
        if (res == 1) return true;
        else return false;
    }
};