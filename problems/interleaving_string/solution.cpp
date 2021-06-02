class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) return false;
        if (len1 == 0) return (s2 == s3);
        if (len2 == 0) return (s1 == s3);
        int dp[len1][len3][len2 + 1];
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len3; j++) 
                for (int k = 0; k < len2 + 1; k++) 
                    dp[i][j][k] = -1;
        function<bool(int, int, int)> dfs = [&](int l1, int l3, int l2) {
            if (l1 == len1) {
                while (l3 < len3 && l2 < len2) {
                    if (s3[l3] != s2[l2]) return false;
                    l2++, l3++;
                }
                return (l2 == len2);
            };
            if (l3 == len3) return false;
            auto& res = dp[l1][l3][l2];
            if (res != -1) return (bool)res;
            res = 0;
            if (s1[l1] == s3[l3]) res = dfs(l1 + 1, l3 + 1, l2);
            res = res || dfs(l1, l3 + 1, l2 + (s3[l3] == s2[l2]));
            return (bool)res;
        };
        return dfs(0, 0, 0);
    }
};