class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> dp(l1 + 1, vector<int> (l2 + 1, -1));
        function<int(int, int)> dfs = [&](int i1, int i2) {
            if (i1 >= l1) return 0;
            if (i2 >= l2) return 0;
            auto& res = dp[i1][i2];
            if (res != -1) return res;
            res = 0;
            if (text1[i1] == text2[i2]) 
                res = dfs(i1 + 1, i2 + 1) + 1;
            else {
                res = max(dfs(i1 + 1, i2), dfs(i1, i2 + 1));
            }
            return res;
        };
        return dfs(0, 0);
    }
};