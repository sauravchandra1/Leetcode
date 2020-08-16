class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len = s3.size();
        int n = s1.size();
        int m = s2.size();
        if (n + m != len) return false;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        function<int(int, int)> dfs = [&](int l1, int l2) {
            if (l1 == n && l2 == m) return 1;
            auto &res = dp[l1][l2];
            if (res != -1) return res;
            res = 0;
            int l3 = l1 + l2;
            int a = 0, b = 0;
            if (l1 < n && l3 < len && s3[l3] == s1[l1]) {
                a = dfs(l1 + 1, l2);
            }
            if (l2 < m && l3 < len && s3[l3] == s2[l2]) {
                b = dfs(l1, l2 + 1);
            }
            res = max(a, b);
            return res;
        };
        int ans = dfs(0, 0);
        if (ans == 1) return true;
        else return false;
    }
};