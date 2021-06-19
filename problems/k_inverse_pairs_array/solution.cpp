class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> prefix(2, vector<int> (k + 1, 0));
        const int mod = 1e9 + 7;
        if (k > (n * (n - 1)) / 2) return 0;
        int ok = 1;
        prefix[0][0] = 1;
        long long sum;
        int len = 1, lastLen, l, r;
        for (int i = 2; i <= n; i++) {
            lastLen = len + 1;
            len = min(k, (i * (i - 1)) / 2);
            sum = l = r = 0;
            for (int j = 0; j <= len; j++) {
                if (j < lastLen) 
                    sum += prefix[1 - ok][l++]; 
                if (j >= i) 
                    sum -= prefix[1 - ok][r++];
                sum += mod;
                sum %= mod;
                prefix[ok][j] = sum;
            }
            ok = 1 - ok;
        }
        return prefix[1 - ok][k];
    }
};