class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + piles[i];
        auto get = [&](int l, int r) {
            return (prefix[r + 1] - prefix[l]);
        };
        function<int(int, int)> dfs = [&](int l, int r) {
            if (l == r) return piles[l];
            auto& res = dp[l][r];
            if (res != -1) return res;
            res = piles[l] + get(l + 1, r) - dfs(l + 1, r);
            res = max(res, piles[r] + get(l, r - 1) - dfs(l, r - 1));
            return res;
        };
        int A = dfs(0, n - 1);
        int L = get(0, n - 1) - A;
        if (A > L) return true;
        else return false;
    }
};