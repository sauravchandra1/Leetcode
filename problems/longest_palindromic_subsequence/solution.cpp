class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        function<int(int, int)> dfs = [&](int l, int r) {
            if (l == r) return 1;
            if (l > r) return 0;
            auto &res = dp[l][r];
            if (res != -1) return res;
            res = 0;
            int a = 0, b = 0, c = 0;
            if (s[l] == s[r]) a = dfs(l + 1, r - 1) + 2;
            b = dfs(l + 1, r);
            c = dfs(l, r - 1);
            res = max(a, b);
            res = max(res, c);
            return res;
        };
        return dfs(0, n - 1);
    }
};