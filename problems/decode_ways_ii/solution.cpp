class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        const int mod = 1e9 + 7;
        vector<long long> dp(len + 1);
        dp[0] = 1;
        if (s[0] == '*') dp[1] = 9;
        else if (s[0] != '0') dp[1] = 1;
        for (int i = 2; i <= len; i++) {
            if (s[i - 1] == '*') dp[i] = dp[i - 1] * 9;
            else if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (s[i - 2] >= '1' && s[i - 2] <= '9') {
                if (s[i - 1] != '*') {
                    int num = int(s[i - 2] - '0') * 10 + int(s[i - 1] - '0');
                    if (num <= 26) dp[i] += dp[i - 2];
                } else {
                    if (s[i - 2] == '1') dp[i] += dp[i - 2] * 9;
                    else if (s[i - 2] == '2') dp[i] += dp[i - 2] * 6;
                }
            } else if (s[i - 2] == '*') {
                if (s[i - 1] != '*') {
                    if (s[i - 1] > '6') dp[i] += dp[i - 2];
                    else dp[i] += dp[i - 2] * 2;
                } else dp[i] += dp[i - 2] * 15;
            }
            dp[i] %= mod;
        }
        return dp[len];
    }
};