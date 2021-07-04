class Solution {
public:
    int countVowelPermutation(int n) {
        if (n == 1) return 5;
        const int N = 5;
        const int mod = 1e9 + 7;
        vector<vector<long long>> dp(2, vector<long long>(N, 1));
        dp[0][0] = 3;
        dp[0][1] = 2;
        dp[0][2] = 2;
        dp[0][3] = 1;
        dp[0][4] = 2;
        bool idx = 0;
        for (int i = 3; i <= n; i++) {
            idx = 1 - idx;
            dp[idx][0] = (dp[1 - idx][1] + dp[1 - idx][2] + dp[1 - idx][4]) % mod;
            dp[idx][1] = (dp[1 - idx][0] + dp[1 - idx][2]) % mod;
            dp[idx][2] = (dp[1 - idx][1] + dp[1 - idx][3]) % mod;
            dp[idx][3] = (dp[1 - idx][2]) % mod;
            dp[idx][4] = (dp[1 - idx][2] + dp[1 - idx][3]) % mod;
        }
        return (dp[idx][0] % mod + dp[idx][1] % mod  + dp[idx][2] % mod  + dp[idx][3] % mod  + dp[idx][4] % mod  + mod) % mod;
    }
};