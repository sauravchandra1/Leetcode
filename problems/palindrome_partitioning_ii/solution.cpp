class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        auto check = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++, r--;
            }
            return true;
        };
        function<int(int)> dfs = [&](int idx) {
            if (idx == n - 1) return 0;
            auto& res = dp[idx];
            if (res != -1) return res;
            if (check(idx, n - 1)) {
                res = 0;
                return res;
            } else {
                res = 1e9;
                for (int i = idx + 1; i < n; i++) {
                    if (check(idx, i - 1)) {
                        res = min(res, dfs(i) + 1);
                    }
                }
            }
            return res;
        };
        return dfs(0);
    }
};