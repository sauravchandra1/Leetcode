class Solution {
public:
    int numDecodings(string s) {
        const int N = 26;
        int n = s.size();
        auto isFine = [](char a, char b) {
            int num = (a - '0') * 10 + (b - '0');
            return ((num > N || a == '0') ? false : true);
        };
        vector<int> dp(n, -1);
        function<int(int)> dfs = [&](int idx) {
            if (idx == n) return 1;
            if (s[idx] == '0') return 0;
            if (idx == n - 1) return 1;
            auto& res = dp[idx];
            if (res != -1) return res;
            if (s[idx + 1] == '0') {
                if (!isFine(s[idx], s[idx + 1])) return (res = 0);
                res = dfs(idx + 2);
            }
            else {
                res = dfs(idx + 1);
                if (isFine(s[idx], s[idx + 1])) res += dfs(idx + 2);
            }
            return res;
        };
        return dfs(0);
    }
};