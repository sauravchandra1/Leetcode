class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        const int inf = 1e9;
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        function<int(int, int)> dfs = [&](int i1, int i2) {
            if (i2 == l2) return (l1 - i1);
            if (i1 == l1) return (l2 - i2);
            auto& res = dp[i1][i2];
            if (res != -1) return res;
            res = inf;
            if (word1[i1] == word2[i2]) 
                res = min(res, dfs(i1 + 1, i2 + 1));
            else {
                res = min(res, dfs(i1, i2 + 1) + 1);
                res = min(res, dfs(i1 + 1, i2) + 1);
                res = min(res, dfs(i1 + 1, i2 + 1) + 1);
            }
            return res;
            
        };
        return dfs(0, 0);
    }
};