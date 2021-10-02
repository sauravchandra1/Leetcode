class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        const int inf = 1e9;
        function<int(int, int)> dfs = [&](int r, int c) {
            if (r >= n || c >= m) return inf;
            if (r == n - 1 && c == m - 1) 
                return (dungeon[r][c] <= 0 ? abs(dungeon[r][c]) + 1 : 1);
            auto& res = dp[r][c];
            if (res != -1) return res;
            int right = dfs(r, c + 1);
            int down = dfs(r + 1, c);
            if (dungeon[r][c] > 0) {
                right = max(1, right - dungeon[r][c]);
                down = max(1, down - dungeon[r][c]);
            } else {
                right += abs(dungeon[r][c]);
                down += abs(dungeon[r][c]);
            }
            res = min(right, down);
            return res;
        };
        return dfs(0, 0);
    }
};